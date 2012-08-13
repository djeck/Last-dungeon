#ifndef ENUMTRAITEMENT_H
#define ENUMTRAITEMENT_H

#include <SFML/Network.hpp>

namespace LD
{
    /** @brief TypeInstruction */
    typedef sf::Uint16 TypeInstruction;

    /** @brief constantes pour les fonctions de traitement client */
    namespace TRAIT_CLIENT
    {
        /** @brief constantes ayant un rapport avec la connexion */
        namespace CONNEXION
        {
            /** @brief constantes ayant un rapport avec la connexion
                @enum CLOSE_SERVEUR : fermeture du serveur
                @enum CLOSE_LISTENER : les connexions entrantes ne sont plus authorisées (surcharge du serveur)
                @enum IP_BAN : l'IP a été bannie
                @enum FAUXID : l'indentifiant est incorrect
                @enum BLOQUE : le compte est bloqué
                @enum BANNI : le compte a été banni de manière définitive
                @enum ADMIN_BAD_PORT : l'administrateur utilise le port client pour se connecter
                @enum DEJACO : le joueur est déjà connecté
                @enum REUSSIE : la connexion a réussie
 */
            enum{CLOSE_SERVEUR, CLOSE_LISTENER, IP_BAN, FAUXID, BLOQUE, BANNI, ADMIN_BAD_PORT, DEJACO, REUSSIE};
        }
        /** @brief marque la fin de l'énumération */
        enum{FIN = CONNEXION::REUSSIE};
    }


    /** @brief constantes pour les fonctions de traitement serveur */
    namespace TRAIT_SERVEUR
    {
        /** @brief fonctions d'administrations */
        namespace ADMINISTRATION
        {
            /** @brief constantes pour les fonctions d'administrations
                @enum CLOSE_PGRM: Arrête le serveur */
            enum{CLOSE_PGRM};
        }

        /** @brief fonctions de base du joueur */
        namespace BASE_JOUEUR
        {
            /** @brief constantes pour les fonctions de bases du joueur
              @enum DECO : le joueur souhaite se déconnecter */
            enum{DECO = ADMINISTRATION::CLOSE_PGRM + 1};
        }

        /** @brief marque la fin de l'énumération */
        enum{FIN = BASE_JOUEUR::DECO};
    }

}


#endif // ENUMTRAITEMENT_H
