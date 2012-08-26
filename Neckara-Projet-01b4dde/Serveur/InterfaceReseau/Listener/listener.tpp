#ifndef LISTENER_TPP
#define LISTENER_TPP

#include "listener.h"

namespace LD
{
    template<typename ModeTraitement, typename Logs, typename BloqueConnexion, typename CloseConnexion>
    Listener<ModeTraitement, Logs, BloqueConnexion, CloseConnexion>::Listener(unsigned int port, bool & running,
                                                                              int nbThread, int nbSec, const bool & isCloseListener, const bool & isBloqueEntrant, typename ModeTraitement::Cible & cible)
        : timeout(sf::seconds(nbSec)),port(port),running(running), nbThread(nbThread),
        isCloseListener(isCloseListener), isBloqueEntrant(isBloqueEntrant), cible(cible)
    {
    }

    template<typename ModeTraitement, typename Logs, typename BloqueConnexion, typename CloseConnexion>
    Listener<ModeTraitement, Logs, BloqueConnexion, CloseConnexion>::~Listener()
    {
    }

    template<typename ModeTraitement, typename Logs, typename BloqueConnexion, typename CloseConnexion>
    void Listener<ModeTraitement, Logs, BloqueConnexion, CloseConnexion>::startEcoute(sf::TcpListener & listener, sf::SocketSelector & selector)
    {
        sf::Socket::Status status;
        status = listener.listen(port);
        logs.startEcoute(status);
        selector.add(listener);
    }


    template<typename ModeTraitement, typename Logs, typename BloqueConnexion, typename CloseConnexion>
    void Listener<ModeTraitement, Logs, BloqueConnexion, CloseConnexion>::filtrageEntrant(sf::TcpListener & listener)
    {
        sf::TcpSocket* client = new sf::TcpSocket;
        if (listener.accept(*client) == sf::Socket::Done)
        {
            if(bloqueCo.isBloque(client, isBloqueEntrant) )
            {
                return;
            }

            std::string raison;
            std::string ip = client->getRemoteAddress().toString();
            if(RequeteBDD::isBanni(ip, raison) )
            {
                sf::Packet paquet;
                paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::IP_BAN;
                paquet << raison;
                client->send(paquet);
                client->disconnect();

                logs.coBanni();

                delete client;
            }
            else
            {
                addSocket(*client);
                logs.filtrageOk();
            }
        }
    }


    template<typename ModeTraitement, typename Logs, typename BloqueConnexion, typename CloseConnexion>
    void Listener<ModeTraitement, Logs, BloqueConnexion, CloseConnexion>::addSocket(sf::TcpSocket & s)
    {
        Joueur * j = new Joueur(*this, s, nbThread);

        mode.entrer();

        selector->add(s);

        listeSocket.push_back(j);

        mode.sortir();
    }

    template<typename ModeTraitement, typename Logs, typename BloqueConnexion, typename CloseConnexion>
    void Listener<ModeTraitement, Logs, BloqueConnexion, CloseConnexion>::delSocket(Joueur & j)
    {
        mode.entrer();

        std::list<Joueur *>::iterator p = listeSocket.begin();
        std::list<Joueur *>::const_iterator const fin = listeSocket.end();

        for( ; p != fin ; ++p)
            if(*p == &j)
            {
                selector->remove( (*p)->socket);
                (*p)->socket.disconnect();
                listeSocket.erase(p);
                break;
            }

        mode.sortir();
    }


    template<typename ModeTraitement, typename Logs, typename BloqueConnexion, typename CloseConnexion>
    void Listener<ModeTraitement, Logs, BloqueConnexion, CloseConnexion>::close(void)
    {
        logs.close();
        mode.entrer();
        for (ListeSocket::iterator it = listeSocket.begin(); it != listeSocket.end(); )
        {
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::CLOSE_SERVEUR; //déconnexion
            //listeInstruction.push_pack(paquet, **it);
            (*it)->socket.disconnect();
            Joueur::deleteJoueur(**it);
            selector->remove( (*it)->socket);
            (*it)->socket.disconnect();
            it = listeSocket.erase(it);
        }
        mode.sortir();
        closeCo.wait();
    }


    template<typename ModeTraitement, typename Logs, typename BloqueConnexion, typename CloseConnexion>
    void Listener<ModeTraitement, Logs, BloqueConnexion, CloseConnexion>::start(void)
    {
        do
        {
            sf::TcpListener listener;
            sf::SocketSelector selector;
            this->selector = &selector;
            startEcoute(listener, selector);

            bool isReady = false;

            while( closeCo.boucle(isCloseListener, running) )
            {
                if(isReady)
                {
                    if (selector.isReady(listener) )
                    {
                        filtrageEntrant(listener);
                    }
                    else
                    {
                        // The listener socket is not ready, test all other sockets (the clients)
                        mode.entrer();
                        for (ListeSocket::iterator it = listeSocket.begin(); it != listeSocket.end(); ++it)
                        {
                            sf::TcpSocket & client = (*it)->socket;
                            if (selector.isReady(client))
                            {
                                // The client has sent some data, we can receive it
                                sf::Packet * packet = new sf::Packet;
                                if ( (client.receive(*packet) ) != sf::Socket::Done)
                                {
                                    std::cout << "Erreur socket" << std::endl;
                                    selector.remove(client);
                                    client.disconnect();
                                    packet->clear();
                                    *packet << (TypeInstruction)TRAIT_SERVEUR::BASE_JOUEUR::DECO;
                                }
                                mode.traiter(*packet, **it, cible); //TODO ajouter un itérateur et retourner un itérateur sinon plante en cas de mauvaise connexion
                                //listeInstruction.push_pack();
                            }
                        }
                        mode.sortir();
                    }
                }
                isReady = selector.wait(timeout);
            }

            selector.remove(listener);
            listener.close();
            close();
        } while(running);
    }
}

#endif // LISTENER_TPP
