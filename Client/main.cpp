/**
@mainpage Client partiel du jeux développé pour les tests du serveur.
On utilise un interface console, après avoir lancé le serveur, il suffit de lancer le client, d'entrer le pseudo puis le mot de passe pour se connecter

Crtl+C pour quitter sous Linux

Pour plus de détails, référez-vous au README se trouvant à la racine du dépôt github : https://github.com/Neckara/Projet
*/

// Penser à inclure les commentaires de premières pages

#include "../Communs/logger.h"
#include <SFML/Network.hpp>
#include "../Communs/Param.h"


/** @brief Traite le paquet reçu côté client */
void traitement(sf::Packet & paquet);

/** @brief Traite le paquet reçu côté client si celui-ci traite de la connexion */
void traitement_connexion(sf::Packet & paquet);

#include "../../Serveur/Serveur/sha512.h"
int main(void)
{
     sf::TcpSocket socket;
     socket.connect("127.0.0.1", LD::ADMINISTRATEUR_PARAM::PORT);

     // Send a message to the connected host
     sf::Packet packet;
     std::cout << "Administrateur veuillez vous identifier" << std::endl;
     std::string login, password;
     std::cin >> login;
     std::cin.ignore();
     std::cin >> password;
     std::cin.ignore();
     packet << login;
     sf::Uint32 * hash = (sf::Uint32 *)LD::Sha512(password).getHash();
     for(int i = 0; i != 16; ++i)
     {
         packet << hash[i];
     }
     socket.send(packet);


     sf::SocketSelector selector;
     selector.add(socket);

     bool running;

     while(running)
     {
         selector.wait();
         if(selector.isReady(socket))
         {
             sf::Packet packet;
             if(socket.receive(packet) == sf::Socket::Done)
             {
                 traitement(packet);
             }
             else
                 running = false;
         }
         else running = false;
    }
    return 0;
}

void traitement(sf::Packet & paquet)
{
    sf::Uint16 x;
    paquet >> x;
    switch(x)
    {
        case LD::TRAITEMENT_PARAM::CONNEXION :
            traitement_connexion(paquet);
        break;
        default :
                std::cout << "Erreur traitement inconnu!" << std::endl;
        break;
    }

}

void traitement_connexion(sf::Packet & paquet)
{
    bool connecte;
    paquet >> connecte;
    if(connecte)
    {
        std::cout << "Connexion réussie" << std::endl;
        sf::Uint32 nbEchec;
        paquet >> nbEchec;
        std::cout << "Il y a eu " << nbEchec << " tentative(s) de connexions infructueuses à votre compte depuis votre dernière visite" << std::endl;
        return;
    }
    sf::Uint16 x;
    paquet >> x;
    switch(x)
    {
        case LD::TRAITEMENT_PARAM::CONNEXION_C::IPBAN :
        {
            std::string raison;
            paquet >> raison;
            std::cout << "Votre adresse a été bannie pour la raison suivante : " << raison << std::endl;
        }
        break;
        case LD::TRAITEMENT_PARAM::CONNEXION_C::FAUXID :
            std::cout << "Mauvais login ou mot de passe" << std::endl;
        break;
        case LD::TRAITEMENT_PARAM::CONNEXION_C::BANNI :
        {
            std::string raison;
            paquet >> raison;
            std::cout << "Vous avez été bannie pour la raison suivante : " << raison << std::endl;
        }
        break;
        case LD::TRAITEMENT_PARAM::CONNEXION_C::BLOQUE :
        {
            sf::Uint32 temps;
            paquet >> temps;
            std::string raison;
            paquet >> raison;
            if(raison != "") raison = "pour la raison suivante : " + raison;
            std::cout << "Votre compte a été bloqué" << raison  <<", attendez " << temps/3600 << "H" << (temps/60)%60 << "min" << temps%60 << "sec avant de pouvoir vous reconnecter" << std::endl;
        }
        break;
        case LD::TRAITEMENT_PARAM::CONNEXION_C::DEJACO :
        std::cout << "Erreur, vous êtes déjà connecté!" << std::endl;

        break;
        default :
                std::cout << "Erreur reponse de connexion inconnu !" << std::endl;
        break;
    }

}
