#ifndef ORDREJOUEUR_H
#define ORDREJOUEUR_H
/* TODO :   temps/joueurs -> passer le tour automatiquement (=timer)
            abandonner
            TraiterFinDeJeux + ignorerGroupe
            Classe Transmission des données. (classe Reception lors du mode multi)
  */
#include <vector>

namespace LD
{
    namespace GO
    {
        class Equipe;
        class Joueur;

        /** @brief détermine l'ordre de jeux des joueurs */
        class OrdreJoueur
        {
        public:
            OrdreJoueur() : nbTours(0), numEquipe(0), nbHandicap(0){}
            virtual bool isTour(Joueur * j){ return j == currentJoueur; }
            /** @brief retourne true si on change de tour */
            virtual bool aJoue(Joueur * j);
            virtual void reserveEquipe(int nbEquipe){ listeEquipe.reserve(nbEquipe); }
            virtual void addEquipe(Equipe * equipe){ listeEquipe.push_back(equipe); }
            void setNbTourMax(int nbTour){ nbTours = nbTour; }
            virtual ~OrdreJoueur(){}
            bool isFinPartie(){ return currentJoueur == NULL; }
            /** @brief démarre le comptage des tours */
            virtual void start(void);
            virtual bool passer(Joueur * joueur);
        protected :
            /** @brief Joueur dont c'est le tour de jouer */
            Joueur * currentJoueur;
            /** @brief Equipes */
            typedef std::vector<Equipe *> ListeEquipe;
            ListeEquipe listeEquipe;
            /** @brief Nombre de tours */
            int nbTours;
            /** @brief Nombre d'équipe */
            int nbEquipe;
            /** @brief Numéro de l'équipe en cours */
            int numEquipe;
            /** @brief Numéro du prochain joueur pour chaque équipe */
            std::vector<int> nextJoueur;
            /** @brief met le prochain joueur */
            bool setNextJoueur(Joueur * joueur);
            /** @brief nombre de tours passés */
            int nbTourPasses;
            /** @brief nombre total d'handicap à jouer */
            int nbHandicap;
            /** @brief nombres de joueurs ayant passé son tour */
            int nbJoueurPasse;
        };
    }
}

#endif // ORDREJOUEUR_H
