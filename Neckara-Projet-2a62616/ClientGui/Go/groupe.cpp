#include "groupe.h"
#include "pion.h"
#include "joueur.h"

namespace LD
{
    namespace GO
    {
        Groupe::Groupe(Pion * pion, int type)  : nbPion(1), type(type), liberte(4), equipe(pion->joueur->equipe), listePion(1, pion)
        {}

        Groupe * Groupe::fusionGroupe(Groupe * groupe)
        {
            // on g�re l'�ventualit� d'une incompatibilit� de fusion.
            if(! peutFusionner(groupe->type) )
            {
                if( ! groupe->peutFusionner(type) )
                    throw("Erreur, groupe infusionnables");
                else
                    return groupe->fusionGroupe(this);
                return NULL;
            }
            ListePion::const_iterator const fin = groupe->listePion.end();
            ListePion::iterator p = groupe->listePion.begin();
            for(; p != fin; ++p)
            {
                (*p)->groupe = this;
                listePion.push_back(*p);
            }
            //les libert� ont d�j� �t� d�cr�ment�es de 2 lors du test
            liberte += groupe->liberte;
            nbPion += groupe->nbPion;
            delete groupe;
            return this;
        }

        void Groupe::setPointOnDeath(Pion * p)
        {
            p->joueur->addPoint(nbPion);
        }

    }
}
