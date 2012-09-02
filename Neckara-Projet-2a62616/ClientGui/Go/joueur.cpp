#include "joueur.h"
#include "equipe.h"

namespace LD
{
    namespace GO
    {
        Joueur::Joueur(Equipe * equipe, int score, int handicap) :
           equipe(equipe), handicap(handicap), score(score)
        {
            equipe->addJoueur(this);
            equipe->addPoint(score);
        }

        void Joueur::addPoint(int nbPoint)
        {
            score += nbPoint;
            equipe->addPoint(nbPoint);
        }
    }
}
