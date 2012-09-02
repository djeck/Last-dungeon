#ifndef EQUIPE_H
#define EQUIPE_H

#include<vector>

namespace LD
{
    namespace GO
    {
        class Joueur;
        class Equipe
        {
        public:
            Equipe();
            virtual ~Equipe();
            virtual void addPoint(int point){ score += point; }
        protected :
            /** @brief nombre de point que possède l'équipe */
            unsigned int score;
            /** @brief membres de l'équipe */
            typedef std::vector<Joueur *> ListeJoueur;
            ListeJoueur listeJoueur;
        public :
            void addJoueur(Joueur * joueur){ listeJoueur.push_back(joueur); }
            friend class OrdreJoueur;
        };
    }
}

#endif // EQUIPE_H
