#include "controleur.h"
#include "pion.h"
#include "socle.h"
#include "plateau.h"
#include "ordrejoueur.h"

namespace LD
{
    namespace GO
    {
        void Controleur::posePion(Pion * pion)
        {
            if(ordreJoueur->isTour(pion->joueur) )
                ;//�chec
            if( pion->socle->getPlateau()->onPose(pion) )
            {
                //r�ussi
                ordreJoueur->aJoue(pion->joueur);
                if( ordreJoueur->isFinPartie() )
                    ;//fin de la partie
            }
            else
            {
                //�chec
            }
        }

        void Controleur::passer(Plateau * plateau, Joueur * joueur)
        {
            if(plateau)
                plateau->passer(joueur);
            else
                ordreJoueur->passer(joueur);//
            if( ordreJoueur->isFinPartie() )
                ;//fin de la partie
        }
    }
}
