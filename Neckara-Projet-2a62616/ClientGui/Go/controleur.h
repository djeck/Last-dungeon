#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <iostream>
#include <vector>

namespace LD
{
    namespace GO
    {
        class Pion;
        class Socle;
        class Plateau;
        class OrdreJoueur;
        class Joueur;

        class Controleur
        {
        public:
             typedef std::vector<Plateau *> ListePlateau;
            /** initialisation de toutes les règles */
            Controleur(OrdreJoueur * ordre, int nbPlateau = 0) : listePlateau(nbPlateau, (Plateau *)NULL), ordreJoueur(ordre) {}
            /** @brief On essaye de poser le pion */
            virtual void posePion(Pion *);
            /** @brief On ajoute un plateau */
            void addPlateau(Plateau * plateau){ listePlateau.push_back(plateau); }
            /** @brief Passer son tour */
            virtual void passer(Plateau *, Joueur *);
        protected :
            /** @brief nécessaire pour le 1vs1, dernier socle surlequel a été posé un pion */
            Socle * lastSocle[2];
            /** @brief liste des plateaux */
            ListePlateau listePlateau;
            /** @brief Ordre de jeux des joueurs */
            OrdreJoueur * ordreJoueur;
        };
    }
}


#endif // CONTROLEUR_H
