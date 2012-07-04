#ifndef SERVEUR_H
#define SERVEUR_H

#include <SFML/Network.hpp>
#include "InterfaceReseau/listeinstruction.h"
#include "InterfaceReseau/listejoueurs.h"
#include "../Communs/Param.h"
#include "InterfaceReseau/listener.h"
#include "InterfaceReseau/paramtraitement.h"

namespace LD
{
    /** @brief défini le serveur */
    class Serveur
    {
    public:
        /** @brief Construit un serveur, lance les threads horaires */
        Serveur(unsigned int port = CO_JOUEURS::PORT, int nbThread = CO_JOUEURS::NB_THREAD);

        /** @brief Lance le thread administrateur */
        void startAdmin(void);

        /** @brief Démarre le serveur et les threads producteurs (lecture des flux de données) ainsi que les threads rédacteurs (traitement des données lues) */
        void start();

        /** @brief nombre de thread consommateurs */
        int nbThread;

        /** @brief port d'écoute pour les joueurs */
        unsigned int port;

        /** @brief Quand il passe à false, arrête le serveur */
        bool running;

        /** @brief liste d'instructions */
        ListeInstruction listeInstruction;

        /** @brief quand passe à true, arrête les connexions entrantes */
        bool coEntrant;


        /** @brief quand passe à true, bloque les threads */
        bool closeServeurClient;

        /** @brief permet de bloquer les threads et de les débloquer */
        sf::Mutex verrou;


        /** @brief liste de tous les joueurs connectés */
        ListeJoueurs listeJoueurs;

        /** @brief paramètres nécessaires aux fonctions de traitement d'instructions */
        ParamTraitement param;
    };
}
#endif // SERVEUR_H
