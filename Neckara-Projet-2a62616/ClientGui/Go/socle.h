#ifndef SOCLE_H
#define SOCLE_H

#include<iostream>
#include <vector>

namespace LD
{
    namespace GO
    {
        class VirtualEffet;
        class Pion;
        class Plateau;

        class Socle
        {
        public:
             typedef std::vector<Socle *> ListeSocle;
            /** @brief créé un socle.
                @param VirtualEffet * : liste des règles spécifique au socle
                @param Pion * : Pion d'origine posé sur le socle */
            Socle(Plateau * plateau, int nbVoisin = 4, VirtualEffet * effet = NULL, Pion * pion = NULL) : plateau(plateau), listeEffet(effet), pion(pion), listeSocle(nbVoisin, (Socle *)NULL){}
            virtual ~Socle();
            /** @brief indique si on peut poser le pion sur le socle */
            virtual bool isFreeForPion(Pion * pion){ return pion == NULL; }
            /** @brief pose le pion sur le socle, retourne false en cas d'erreur */
            virtual bool setPion(Pion * pion);
            /** @brief exécute l'(les) effet(s) du socle */
            void executeEffet(Pion * pion);
            /** @brief ajoute un voisin */
            void addVoisin(Socle * socle){ listeSocle.push_back(socle);}
            /** @brief modifie un voisin */
            void modifierVoisin(int numVoisin, Socle * voisin){ listeSocle[numVoisin] = voisin; }
            /** @brief obtenir la liste des voisins */
            const ListeSocle & getVoisin(){ return listeSocle; }
            Plateau * getPlateau(void){ return plateau; }
        protected :
            /** @brief Plateau auquel appartient le socle */
            Plateau * plateau;
            VirtualEffet * listeEffet;
            Pion * pion;
            ListeSocle listeSocle;
            friend class Plateau;
        };
    }
}

#endif // SOCLE_H
