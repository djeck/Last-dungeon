#include "ordrejoueur.h"
#include "equipe.h"
#include "joueur.h"

namespace LD
{
    namespace GO
    {
        void OrdreJoueur::start()
        {
            nbEquipe = listeEquipe.size();
            nextJoueur = std::vector<int>(nbEquipe, 0);
            nbJoueurPasse  = nbEquipe;

            ListeEquipe::const_iterator const fin = listeEquipe.end();
            ListeEquipe::iterator p = listeEquipe.begin();
            for( ; p != fin; ++p)
            {
                Equipe::ListeJoueur::const_iterator const finJ = (*p)->listeJoueur.begin();
                Equipe::ListeJoueur::iterator pJ = (*p)->listeJoueur.end();
                for( ; pJ != finJ; ++p)
                    nbHandicap += (*pJ)->handicap;
            }
            currentJoueur = listeEquipe[0]->listeJoueur[0];
        }

        bool OrdreJoueur::aJoue(Joueur *joueur)
        {
            if(joueur != currentJoueur)
                return false;
            nbJoueurPasse = nbEquipe;
            return setNextJoueur(joueur);
        }

        bool OrdreJoueur::passer(Joueur * joueur)
        {
            if(joueur != currentJoueur)
                return false;
            --nbJoueurPasse;
            return setNextJoueur(joueur);
        }

        bool OrdreJoueur::setNextJoueur(Joueur * joueur)
        {
            if(nbJoueurPasse == 0)
            {
                currentJoueur = NULL;
                return true;
            }

            do
            {
                if(++numEquipe == nbEquipe)
                {
                    numEquipe = 0;
                    if(--nbTours == 0)
                    {
                        if(nbHandicap == 0)
                        {
                            currentJoueur = NULL;
                            return true;
                        }
                        else
                            ++nbTours;
                    }

                }
                currentJoueur = listeEquipe[numEquipe]->listeJoueur[ nextJoueur[numEquipe] ];
                if(++nextJoueur[numEquipe] == (int)listeEquipe[numEquipe]->listeJoueur.size() )
                    nextJoueur[numEquipe] = 0;

            }
            while(nbHandicap != 0 && currentJoueur->handicap == 0);
            return false;
        }
    }
}
