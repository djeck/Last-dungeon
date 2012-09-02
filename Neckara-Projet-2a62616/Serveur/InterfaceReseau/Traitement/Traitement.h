#ifndef TRAITEMENT_H
#define TRAITEMENT_H


#include <SFML/System.hpp>

#include "virtualtraitement.h"

#include "../listejoueurs.h"
#include "../paramtraitement.h"
#include "../../../Communs/enumTraitement.h"
#include "../listefonctionserveur.h"
#include "../../../Communs/requetebdd.h"
#include "../../../Communs/Param.h"
#include "../../../Communs/sha512.h"

namespace LD
{
    template<typename Logs, typename Mode>
    class Traitement : VirtualTraitement
    {
    public:
    /** @brief Construit un objet de traitement d'instructions.
            @param ListeJoueurs & listeJoueurs : liste des joueurs connectés
            @param ListeInstruction * listeInstruction : liste des instructions
            @param bool & running : booléen permettant d'arrêter le serveur
            @param bool & coEntrants : booléen permettant d'arrêter les connexions entrantes
            @param Bloque le serveur Joueur mais laisse la possibilité aux administrateurs de se connecter
            @param Bloque le thread listener
    */
        Traitement(ListeJoueurs & listeJoueurs, ListeInstruction * listeInstruction, bool & running, bool & coEntrants,
                    bool &closeServeurClient, ParamTraitement & param);
        ~Traitement();

        /** @brief démarre le traitement : traite une instruction
                prototype : bool fonctionTraitement(sf::Paquet &, Traitement *)
                Appel : tabFonctionTraitement[i](paquet, this)
        */
        void traiterInstruction(Instruction & instruction);

        /** @brief démarre le traitement d'une seule instruction */
        void traiter(void);
    private :
            /** @brief défini les messages de logs */
            Logs log;
            /** @brief défini le mode de fonctionnement de la classe traitement */
            Mode mode;

            /** @brief connecte le joueur
                @param Instruction & instruction : instruction reçue
                @return : retourne true si la connexion a échouée */
            bool connexion(Instruction & instruction);



            private :

                /** @brief liste de tout les joueurs connectés */
                ListeJoueurs & listeJoueurs;

                /** @brief liste des instructions à traiter */
                ListeInstruction * listeInstruction;

                /** @brief quand running passe à false, on éteint le serveur */
                bool & running;

                /** @brief Bloque les connexions entrantes en cas de surchage du serveur */
                bool & coEntrants;

                /** @brief Bloque le serveur Joueur mais laisse la possibilité aux administrateurs de se connecter */
                bool &closeServeurClient;

                /** @brief Listes de paramètres nécessaires aux fonctions de traitements */
                ParamTraitement & param;
    };

}

#include "Traitement.tpp"

#endif // TRAITEMENT_H
