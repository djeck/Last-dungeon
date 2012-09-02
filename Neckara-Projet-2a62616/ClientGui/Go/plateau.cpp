#include "plateau.h"
#include "pion.h"
#include "socle.h"
#include "joueur.h"

namespace LD
{
    namespace GO
    {
        bool Plateau::onPose(Pion * pion)
        {
            if(ordreJoueur->isTour(pion->joueur) )
                return false;


            if(! pion->socle->isFreeForPion(pion) )
                return false;
            Socle::ListeSocle::const_iterator const fin = pion->socle->getVoisin().end();
            Socle::ListeSocle::const_iterator debut = pion->socle->getVoisin().begin();
            Socle::ListeSocle::const_iterator p = debut;
            bool isPosable = false;
            std::list<Groupe *> listeGroupe;
            for(;p != fin; ++p)
            {
                if( (*p)->pion )
                {
                    --pion->groupe->liberte;
                    --(*p)->pion->groupe->liberte;

                    if((*p)->pion->groupe->equipe != pion->groupe->equipe)
                    {
                        if((*p)->pion->groupe->liberte == 0 )
                        {
                            //on mange direct le groupe ;
                            (*p)->pion->groupe->setPointOnDeath(pion);
                            isPosable = true;
                        }
                    }
                    else
                    {
                        listeGroupe.push_back( (*p)->pion->groupe);
                    }


                }
                else
                    isPosable = true;
            }

            listeGroupe.unique();
            std::list<Groupe *>::const_iterator const finG = listeGroupe.end();
            std::list<Groupe *>::iterator debutG  = listeGroupe.begin();
            std::list<Groupe *>::iterator pG = debutG;
            for( ; pG != finG; ++pG)
            {
                if( (*pG)->liberte != 0)
                {
                    isPosable = true;
                    break;
                }
            }

            if( ! isPosable && pion->groupe->liberte == 0) //on prévoit le coup de pions super cheat.
            {
                //on remet les libertés normalement, les actions ont été annulées
                for(p = debut; p != fin; ++p)
                    if( (*p)->pion )
                        ++(*p)->pion->groupe->liberte;
                return false;
            }

            //fusion des groupes
            for(pG = debutG; pG != finG; ++pG)
            {
                pion->groupe = pion->groupe->fusionGroupe(*pG);
            }

            //réussi
            pion->socle->executeEffet(pion);
            ordreJoueur->aJoue(pion->joueur);
            if( ordreJoueur->isFinPartie() )
                ;//fin de la partie
            return true;
        }
    }
}
