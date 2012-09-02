#ifndef ENVIRONNEMENT_H
#define ENVIRONNEMENT_H

#include<list>
#include<SFML/Network.hpp>
#include <semaphore.h>

#include "InfoJoueur.h"

namespace LD
{
/** @brief définie l'environnement de jeux */
    class Environnement
    {
    private :
            typedef std::list<InfoJoueur *> List;
            /** @brief Ensemble des joueurs connectés */
            List joueurConnecte;
            /** @brief sert à l'accès concurent en lecture seule */
            sem_t semaphore;
            /** @brief sert à l'accès non-concurent à l'écriture */
            sf::Mutex verrou;
            /** @brief Maximum de jetons possibles */
            const int nbJetonMax;
    public :
            /** @brief Construit l'environnement
                @param int nbJeton : nombres de jetons disponibles */
            Environnement(int nbJeton);
            /** @brief Détruit l'environnement */
            ~Environnement();
            /** @brief permet d'ajouter un joueur, si la personne est déjà connectée, déconnecte les deux joueurs
                @param  InfoJoueur * : joueur à ajouter
                @return bool : retourne true si la personne est déjà connectée, false sinon. */
            bool addJoueur(InfoJoueur *);
            /** @brief permet de déconnecter un joueur et de le supprimer de la liste
                @param  InfoJoueur * : joueur à supprimer  */
            void decoJoueur(InfoJoueur *);
            /** @brief permet de savoir si un joueur est connecté
                @param  unsigned int id : identifiant de la personne connectée
                @return bool : retourne true si la personne est déjà connectée */
            bool isConnecte(unsigned int id);
            /** @brief permet d'envoyer un paquet en multicast à tous les joueurs connectés
                @param const sf::Packet & paquet : paquet à envoyer */
            void multicast(sf::Packet & paquet);
    };
}
#endif // ENVIRONNEMENT_H
