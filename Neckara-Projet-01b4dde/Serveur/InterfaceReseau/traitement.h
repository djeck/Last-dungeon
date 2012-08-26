#ifndef TRAITEMENT_H
#define TRAITEMENT_H


#include "listeinstruction.h"
#include "listejoueurs.h"
#include "paramtraitement.h"

#include <SFML/System.hpp>

namespace LD
{
    /** @brief Cette classe se charge d'appeler la fonction permettant de traiter les instructions reçues. */
    class Traitement
    {
        public:
        /** @brief Construit un objet de traitement d'instructions.
                @param ListeJoueurs & listeJoueurs : liste des joueurs connectés
                @param ListeInstruction & listeInstruction : liste des instructions
                @param bool & running : booléen permettant d'arrêter le serveur
                @param bool & coEntrants : booléen permettant d'arrêter les connexions entrantes
                @param Bloque le serveur Joueur mais laisse la possibilité aux administrateurs de se connecter
                @param Bloque le thread listener
    */
        Traitement(ListeJoueurs & listeJoueurs, ListeInstruction & listeInstruction, bool & running, bool & coEntrants,
                    bool &closeServeurClient, sf::Mutex &verrou, ParamTraitement & param);
        ~Traitement();

        /** @brief démarre le traitement : prototype type : bool fonctionTraitement(sf::Paquet &, Traitement *)
                Appel : tabFonctionTraitement[i](paquet, this)
        */
        void traiter(void);


        /** @brief connecte le joueur
            @param Instruction & instruction : instruction reçue
            @return : retourne true si la connexion a échouée */
        bool connexion(Instruction & instruction);



        private :

            /** @brief liste de tout les joueurs connectés */
            ListeJoueurs & listeJoueurs;

            /** @brief liste des instructions à traiter */
            ListeInstruction & listeInstruction;

            /** @brief quand running passe à false, on éteint le serveur */
            bool & running;

            /** @brief Bloque les connexions entrantes en cas de surchage du serveur */
            bool & coEntrants;

            /** @brief Bloque le serveur Joueur mais laisse la possibilité aux administrateurs de se connecter */
            bool &closeServeurClient;

            /** @brief Bloque le thread listener */
            sf::Mutex &verrou;

            /** @brief Listes de paramètres nécessaires aux fonctions de traitements */
            ParamTraitement & param;
    };
}
#endif // TRAITEMENT_H
