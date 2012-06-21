#include "serveur.h"
#include "administrateur.h"
#include "../../Console/Console/logger.h"
#include <list>

namespace LD
{
    Serveur::Serveur()
    {
        Administrateur admin;
        //TODO gentillesse
    }

    void Serveur::start()
    { /** TODO : thread client
        sf::Socket::Status status;
        if ( (status = listener.listen(1102) ) )
        {
            //Erreur : TODO : corriger
            std::stringstream log("Erreur Socket : ");
            log << status;
            Logger::addLog(log.str());
            throw(log.str());
        }

        selector.add(listener);
        sf::TcpSocket socket;
        std::list<sf::TcpSocket*> clients;
        while (true) //TODO : condition de fin
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
                        clients.push_back(client);

                        // Add the new client to the selector so that we will
                        // be notified when he sends something
                        selector.add(*client);
                    }
                }
                else
                {
                    // The listener socket is not ready, test all other sockets (the clients)
                    for (std::list<sf::TcpSocket*>::iterator it = clients.begin(); it != clients.end(); ++it)
                    {
                        sf::TcpSocket& client = **it;
                        if (selector.isReady(client))
                        {
                            // The client has sent some data, we can receive it
                            sf::Packet packet;
                            if (client.receive(packet) == sf::Socket::Done)
                            {
                                std::string message;
                                packet >> message;
                                std::cout << "The client said: " << message << std::endl;
                                sf::Packet packet2;
                                packet2 << "Welcome, client";
                                client.send(packet2);

                            }
                        }
                    }
                }
            }
        }

        //TODO fermeture du serveur
        //TODO stop
*/
    }
}
