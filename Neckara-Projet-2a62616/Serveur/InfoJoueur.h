#ifndef INFOJOUEUR_H
#define INFOJOUEUR_H

#include <string>
#include <ctime>

#include <SFML/Network.hpp>

namespace LD
{
/** @brief défini un joueur connecté.
N.B. Un admin est un joueur spécial */
    struct InfoJoueur
    {
/** @brief identifiant (TODO : mettre const) */
        unsigned int id;
/** @brief timestamp de la date où le compte sera débloqué */
        unsigned long long bloque;
/** @brief défini les droits du joueur (un bit à 1 signifie qu'il a le droit, un bit à 0 signifie qu'il ne possède pas de droits */
        unsigned int droits;
/** @brief indique si le joueur est banni */
        bool banni;
/** @brief indique la raison du bannissement ou du blocage */
        std::string raisonBan;
/** @brief indique le nombre de tentative de connexion infructueuses depuis la dernière connexion réussie */
        unsigned short echec;
/** @brief hash du mot de passe du joueur */
        std::string hash;
/** @brief socket sur lequel est connecté le joueur */
        sf::TcpSocket * socket;
    };
}

#endif // INFOJOUEUR_H
