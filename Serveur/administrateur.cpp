#include "administrateur.h"
#include "../../Console/Console/logger.h"
#include "../../Console/Console/requetebdd.h"
#include "../../Console/Console/Param.h"
#include <string>
#include <iomanip>
#include "../Communs/sha512.h"


namespace LD
{
    Administrateur::Administrateur() : running(true), env(new Environnement(5)) //TODO valeur par defaut
    {
        sf::TcpListener listener;
        sf::SocketSelector selector;
        sf::Socket::Status status;
        if ( (status = listener.listen(ADMINISTRATEUR_PARAM::PORT) ) )
        {
            //Erreur : TODO : corriger
            std::stringstream log("Erreur Socket : ");
            log << status;
            Logger::addLog(log.str());
            throw(log.str());
        }

        selector.add(listener);
        Logger::addLog("Démarrage du serveur", LOGGER_PARAM::ADMINISTRATEUR);
        while (running)
        {
            // Make the selector wait for data on any socket
            if (selector.wait())
            {
                // Test the listener
                if (selector.isReady(listener))
                {
                    // The listener is ready: there is a pending connection
                    sf::TcpSocket* client = new sf::TcpSocket;
                    if (listener.accept(*client) == sf::Socket::Done)
                    {
                        // Add the new client to the clients list
                        clients.push_back(new Administrateur::AdminCo(client, env) );
                        //message de log
                        std::string message = "Tentative de connexion : ";
                        std::string ip = client->getRemoteAddress().toString();
                        message += ip;
                        std::string raison;
                        if(RequeteBDD::isBanni(ip, raison) )
                        {
                            message += " : IP BANNIE !";
                            sf::Packet paquet;
                            paquet << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION;
                            paquet << false;
                            paquet << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION_C::IPBAN;
                            paquet << raison;
                            client->send(paquet);
                        }
                        else
                        {
                            // Add the new client to the selector so that we will
                            // be notified when he sends something
                            selector.add(*client);
                        }
                        Logger::addLog(message, LOGGER_PARAM::ADMINISTRATEUR);
                    }
                }
                else
                {
                    // The listener socket is not ready, test all other sockets (the clients)
                    for (std::list<Administrateur::AdminCo *>::iterator it = clients.begin(); it != clients.end(); ++it)
                    {
                        sf::TcpSocket& client = *(*it)->socket;
                        if (selector.isReady(client))
                        {
                            // The client has sent some data, we can receive it
                            sf::Packet packet;
                            if (client.receive(packet) == sf::Socket::Done)
                            {
                                if( (*it)->traitement(packet, this) )
                                {
                                    selector.remove(client);
                                    it = clients.erase(it);
                                }
                            }
                            else
                            {
                                //TODO déconnexion
                                selector.remove(client);
                                it = clients.erase(it);
                            }
                        }
                    }
                }
            }
        }
        listener.close();
    }

    Administrateur::~Administrateur()
    {
        for (std::list<Administrateur::AdminCo *>::iterator it = clients.begin(); it != clients.end(); ++it)
        {
            delete *it;
            it = clients.erase(it);
        }
        delete env;
    }

    Administrateur::AdminCo::AdminCo(sf::TcpSocket * socket, Environnement * env) : socket(socket), connecte(false), env(env){}

    Administrateur::AdminCo::~AdminCo()
    {
        delete socket;
    }

    bool Administrateur::AdminCo::traitement(sf::Packet & paquet, Administrateur * general)
    {
        if(! connecte)
        {
            bool retour = connexionAdmin(paquet);
            if(! retour)
                Logger::addLog(socket->getRemoteAddress().toString() + " : Connexion refusée", LOGGER_PARAM::ADMINISTRATEUR);
            return retour;
        }
        else
        {
            sf::Uint16 typeTraitement;
            paquet >> typeTraitement;
            switch(typeTraitement)
            {
               case TRAITEMENT_PARAM::ADMINISTRATION :
                    general->running = false;
                break;
                case 1 :
                break;
                default :
                        //TODO blocage du compte
                        //TODO alerte
                        return true;
                break;
            }
        }
        return false;
    }

    bool Administrateur::AdminCo::connexionAdmin(sf::Packet & paquet)
    {
        std::string login, password;
        paquet >> login;
        InfoJoueur joueur;
        if(! RequeteBDD::getJoueur(login, joueur) )
        {
            sf::Packet paquet;
            paquet << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION << false << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION_C::FAUXID;
            socket->send(paquet);
            return false;
        }
        if(joueur.bloque > (unsigned long long)time(NULL))
        {
            sf::Packet paquet;
            paquet << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION << false << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION_C::BLOQUE << (sf::Uint32)(joueur.bloque - time(NULL)) << joueur.raisonBan;
            socket->send(paquet);
            return false;
        }
        if(joueur.banni)
        {
            sf::Packet paquet;
            paquet << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION << false << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION_C::BANNI << joueur.raisonBan;
            socket->send(paquet);
            return false;
        }
        unsigned long long hash[8];
        sf::Uint32 * ptr = (sf::Uint32 *)hash;
        for(int i =0; i != 16; ++i, ++ptr)
            paquet >> *ptr;

          if(Sha512(hash).getHexadecimal(password) != joueur.hash)
          {
            ++joueur.echec;
            sf::Packet paquet;
            time_t temps = 0;
            std::string raison = "";
            if( (joueur.echec% ADMINISTRATEUR_PARAM::NB_MAX_ECHEC) == 0)
            {
                time(&temps);
                temps += ADMINISTRATEUR_PARAM::ATTENTE;
                raison = "5 échecs de connexions";
                paquet << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION << false << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION_C::BLOQUE << (sf::Uint32)ADMINISTRATEUR_PARAM::ATTENTE << joueur.raisonBan;
            }
            else
                paquet << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION << false << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION_C::FAUXID;
            RequeteBDD::setBloque(joueur.id, temps, raison, joueur.echec);
            socket->send(paquet);
            return false;
          }
        if(! (joueur.droits & (1<<DROITS::ACCES) ) )
          {
            RequeteBDD::setBanni(joueur.id, "Tentative de hack du serveur");
            sf::Packet paquet;
            paquet << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION << false << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION_C::BANNI << "Tentative de hack du serveur";
            socket->send(paquet);
            return false;
          }
         joueur.socket = socket;
        if(env->addJoueur(&joueur))
         {
            sf::Packet reponse;
            reponse << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION << false << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION_C::DEJACO;
            socket->send(reponse);
            return false;
        }
        RequeteBDD::setBloque(joueur.id, 0, "", 0);
        sf::Packet reponse;
        reponse << (sf::Uint16)TRAITEMENT_PARAM::CONNEXION << true << (sf::Uint32)joueur.echec;
        socket->send(reponse);


        connecte = true;
        return false;
    }
}
