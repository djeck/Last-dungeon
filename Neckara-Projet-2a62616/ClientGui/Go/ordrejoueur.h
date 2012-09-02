#ifndef ORDREJOUEUR_H
#define ORDREJOUEUR_H
/* TODO :   temps/joueurs -> passer le tour automatiquement (=timer)
            abandonner
            TraiterFinDeJeux + ignorerGroupe
            Classe Transmission des donn�es. (classe Reception lors du mode multi)
  */
#include <vector>

namespace LD
{
    namespace GO
    {
        class Equipe;
        class Joueur;

        /** @brief d�termine l'ordre de jeux des joueurs */
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
            /** @brief d�marre le comptage des tours */
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
            /** @brief Nombre d'�quipe */
            int nbEquipe;
            /** @brief Num�ro de l'�quipe en cours */
            int numEquipe;
            /** @brief Num�ro du prochain joueur pour chaque �quipe */
            std::vector<int> nextJoueur;
            /** @brief met le prochain joueur */
            bool setNextJoueur(Joueur * joueur);
            /** @brief nombre de tours pass�s */
            int nbTourPasses;
            /** @brief nombre total d'handicap � jouer */
            int nbHandicap;
            /** @brief nombres de joueurs ayant pass� son tour */
            int nbJoueurPasse;
        };
    }
}

#endif // ORDREJOUEUR_H
