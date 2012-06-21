#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include <SFML/Network.hpp>
#include <list>
#include "environnement.h"

//TODO bannir/télécharger fichiers logs/fermer serveur jeux arrêter serveur

namespace LD
{

    /** @brief Interface d'administration
        /!\ Pas de sécurité, les sockets TCP ont de grandes failles de sécurité, TODO : mettre des socket openSSL ?
        http://www.openssl.org/docs/ssl/ssl.html (gère aussi les timeout)
        Man in the middle : http://en.wikipedia.org/wiki/Man-in-the-middle_attack#Defenses_against_the_attack
        Rq : la structure est à revoir */
    class Administrateur
    {
    private :
            /** @brief booléen arrêtant le thread administrateur */
            bool running;

    public:
        /** @brief Commence la lecture du port administrateur */
        Administrateur();

        /** @brief Destructeur */
        ~Administrateur();

        class AdminCo;
    private :
            /** @brief Liste des administrateurs connectés */
            std::list<Administrateur::AdminCo *> clients;

            /** @brief Environnement */
            Environnement * env;
    };
        /** @brief Classe représentant un administrateur connecté
            Rq : à revoir, cette classe devrait être remplacée par un std::pair<socket &, InfoJoueur * x> avec x à NULL si non connecté  */
    class Administrateur::AdminCo
    {
        private :
                /** @brief pointeur sur le socket avec lequel l'administrateur se connecte */
                sf::TcpSocket * socket;


                /** @brief indique si l'administrateur a réussi l'identification */
                bool connecte;


/** @brief Permet d'instancier un administrateur connecté
                  @param sf::TcpSocket * socket : pointeur sur le socket avec lequel l'administrateur se connecte */
                AdminCo(sf::TcpSocket * socket, Environnement *);

                /** @brief Permet de détruire un administrateur */
                ~AdminCo();

                friend class Administrateur;
                /** @brief environnement général du serveur (liste de tous les connectés), à revoir */
                Environnement * env;


                /** @brief Traite les données reçus
                    @param sf::Packet & paquet : données reçues
                    @return bool : retourne true s'il faut supprimer la socket */
                bool traitement(sf::Packet & paquet, Administrateur * general);



                /** @brief Permet de connecter un administrateur
                    @param sf::Paquet & paquet : paquet envoyé.
                    @return bool : si la connexion a échouée */
                bool connexionAdmin(sf::Packet & paquet);
    };
}

#endif // ADMINISTRATEUR_H
