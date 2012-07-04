#include "listener.h"

#include "../../Communs/logger.h"
#include "../../Communs/requetebdd.h"
#include "../../Communs/enumTraitement.h"

// Rq  : verrou sur la liste de la lecture à la création de l'instruction IMPORTANT
namespace LD
{
    Listener::Listener(unsigned int port,/* const */ bool & running, ListeInstruction & listeInstruction, bool & coEntrants
                       , const bool &closeServeurClient, sf::Mutex &verrou, const int nbThread)
        : listeInstruction(listeInstruction),
        running(running),
        coEntrants(coEntrants),
        closeServeurClient(closeServeurClient),
        verrou(verrou),
        port(port),
        nbThread(nbThread)
    {

    }



    Listener::~Listener()
    {

    }

    void Listener::startEcoute(sf::TcpListener & listener, sf::SocketSelector & selector)
    {
        sf::Socket::Status status;
        if ( (status = listener.listen(port) ) )
        {
            //Erreur : TODO : corriger
            std::stringstream log;
            log << "Erreur Socket listener : " << status;
            Logger::addLog( log.str() );
            throw( log.str() );
        }
       Logger::addLog("Démarrage du serveur");
       selector.add(listener);
    }


    void Listener::filtrageEntrant(sf::TcpListener & listener)
    {
        sf::TcpSocket* client = new sf::TcpSocket;
        if (listener.accept(*client) == sf::Socket::Done)
        {
            if(coEntrants) //si les connexions entrantes sont bloquées
            {
                sf::Packet paquet;
                paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::CLOSE_LISTENER;
                client->send(paquet);
                client->disconnect();
                delete client;
                return;
            }
            std::string raison;
            if(RequeteBDD::isBanni(ip, raison) )
            {
                sf::Packet paquet;
                paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::IP_BAN;
                paquet << raison;
                client->send(paquet);
                client->disconnect();
                delete client;
            }
            else
            {
                addSocket(*client);
            }
        }
    }



    void Listener::start(void)
    {
        while(running)
        {
            sf::TcpListener listener;
            sf::SocketSelector selector;
            this->selector = &selector;
            startEcoute(listener, selector);
            while ( (! closeServeurClient) && running)
            {
                if ( selector.wait(sf::seconds(15) ) ) //TODO mettre à la fin
                {
                    if (selector.isReady(listener) )
                    {
                        filtrageEntrant(listener);
                    }
                    else
                    {
                        // The listener socket is not ready, test all other sockets (the clients)
                        verrouListener.lock();
                        for (ListeSocket::iterator it = listeSocket.begin(); it != listeSocket.end(); ++it)
                        {
                            sf::TcpSocket & client = (*it)->socket;
                            if (selector.isReady(client))
                            {
                                // The client has sent some data, we can receive it
                                sf::Packet packet;
                                if (client.receive(packet) != sf::Socket::Done)
                                {
                                    //TODO
                                    packet.clear();
                                    packet << 0; //déconnexion
                                }
                                listeInstruction.push_pack(packet, **it);
                            }
                        }
                        verrouListener.unlock();
                    }
                }
            }
            listener.close();
            selector.remove(listener);
            close();
        }
    }

    void Listener::close(void)
    {
        Logger::addLog("Fermeture du serveur", LOGGER_PARAM::ADMINISTRATEUR); //message de log de fermeture serveur client
        verrouListener.lock();
        for (ListeSocket::iterator it = listeSocket.begin(); it != listeSocket.end(); )
        {
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::CLOSE_SERVEUR; //déconnexion
            //listeInstruction.push_pack(paquet, **it);
            (*it)->socket.disconnect();
            Joueur::deleteJoueur(**it);
            selector->remove( (*it)->socket);
            it = listeSocket.erase(it);
        }
        verrouListener.unlock();
        if(closeServeurClient)
            verrou.lock(); //TODO
    }

    void Listener::delSocket(Joueur & j)
    {
        verrouListener.lock();

        std::list<Joueur *>::iterator p = listeSocket.begin();
        std::list<Joueur *>::const_iterator const fin = listeSocket.end();

        for( ; p != fin ; ++p)
        if(*p == &j)
        {
            (*p)->socket.disconnect();
            Joueur::deleteJoueur(**p);
            selector->remove( (*p)->socket);
            listeSocket.erase(p);
            break;
        }

        verrouListener.unlock();
    }


    void Listener::addSocket(sf::TcpSocket & s)
    {
        Joueur * j = new Joueur(*this, s, nbThread);

        verrouListener.lock();

        selector->add(s);

        listeSocket.push_back(j);

        verrouListener.unlock();
    }
}
