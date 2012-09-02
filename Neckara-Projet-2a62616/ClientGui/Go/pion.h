#ifndef PIONNORMAL_H
#define PIONNORMAL_H

#include "groupe.h"

namespace LD
{
    namespace GO
    {
        class Socle;
        class Joueur;
        /** @brief Pion normal, tous les pions doivent hériter de celui-ci */
        class Pion
        {
        public:
            /** @brief créé un pion.
              @param Joueur * : joueur tentant de poser le pion
              @param int type : type du pion, 0 signifie un pion normal */
            Pion(Joueur *, Socle * socle, int type = 0) :  type(type), groupe(new Groupe(this)), joueur(joueur), socle(socle) {}
            int getType(void) { return type; }
            virtual ~Pion(){}
            Socle * getSocle(void){ return socle; }
            friend class Groupe;
        protected:
            int type;
            /** @brief Groupe auquel appartient le pion */
            Groupe * groupe;
            /** @brief Joueur ayant posé le pion  */
            Joueur * joueur;
            /** @brief Socle sur lequel on veut poser le pion */
            Socle * socle;
            friend class Controleur;
            friend class Plateau;
        };
    }
}
#endif // PIONNORMAL_H
