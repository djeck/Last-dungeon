#ifndef GROUPE_H
#define GROUPE_H

#include<list>

namespace LD
{
    namespace GO
    {
        class Pion;
        class Equipe;
        /** @brief Detruit un pion */
        class Groupe
        {
        public:
            /** @brief créé un groupe
              @param Pion * pion : unique pion à l'origine du groupe
              @param int type = 0 : type du groupe, 0 pour un groupe normal */
            Groupe(Pion * pion, int type = 0);
            /** @brief fusionne deux groupes
              Attention, les deux groupes peuvent être détruit et laisser place à un tout nouveau groupe !
                @return retourne le groupe ainsi créé */
            virtual Groupe * fusionGroupe(Groupe * groupe);
            /** @brief indique si le groupe peut gérer la fusion avec un groupe de type int type.*/
            virtual bool peutFusionner(int type){  return type == 0; }
            /** @brief met les points à jour lors de la destruction du groupe
                @param Pion * : pion à l'origine de la mort du groupe */
            virtual void setPointOnDeath(Pion *);
            /** @brief met les points à jour lors de la fin de la partie */
            virtual void setPointOnEnd(void){ }
            virtual ~Groupe(){}
        protected :
            /** @brief Nombre de pions contenu dans le groupe */
            int nbPion;
            /** @brief Type du groupe */
            int type;
            /** @brief Liberté du groupe */
            int liberte;
            /** @brief équipe possédant le groupe */
            Equipe * equipe;
            typedef std::list<Pion *> ListePion;
            ListePion listePion;
            friend class Plateau;
        };
    }
}

#endif // GROUPE_H
