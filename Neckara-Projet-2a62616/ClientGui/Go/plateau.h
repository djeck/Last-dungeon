#ifndef PLATEAU_H
#define PLATEAU_H

#include "ordrejoueur.h"

namespace LD
{
    namespace GO
    {
        class Pion;
        class Joueur;
        class Plateau
        {
        public:
            Plateau(OrdreJoueur * ordre) : ordreJoueur(ordre){}
            bool onPose(Pion *);
            bool passer(Joueur * joueur){ return ordreJoueur->passer(joueur); }
        protected :
            OrdreJoueur * ordreJoueur;
        };
    }
}

#endif // PLATEAU_H
