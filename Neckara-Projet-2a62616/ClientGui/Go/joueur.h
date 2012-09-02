#ifndef JOUEUR_H
#define JOUEUR_H

namespace LD
{
    namespace GO
    {
        class Equipe;
        class Joueur
        {
        public:
            Joueur(Equipe * equipe, int score = 0, int handicap = 0);
            virtual ~Joueur(){}
            Equipe * getEquipe(void){ return equipe; }
            virtual void addPoint(int nbPoint);
        protected :
            /** @brief Equipe auquel appartient le joueur */
            Equipe * equipe;
            /** @brief Handicap en faveur du joueur */
            int handicap;
            /** @brief score du joueur */
            int score;
            friend class Groupe;
            friend class OrdreJoueur;
        };
    }
}

#endif // JOUEUR_H
