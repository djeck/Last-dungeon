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
            /** @brief cr�� un groupe
              @param Pion * pion : unique pion � l'origine du groupe
              @param int type = 0 : type du groupe, 0 pour un groupe normal */
            Groupe(Pion * pion, int type = 0);
            /** @brief fusionne deux groupes
              Attention, les deux groupes peuvent �tre d�truit et laisser place � un tout nouveau groupe !
                @return retourne le groupe ainsi cr�� */
            virtual Groupe * fusionGroupe(Groupe * groupe);
            /** @brief indique si le groupe peut g�rer la fusion avec un groupe de type int type.*/
            virtual bool peutFusionner(int type){  return type == 0; }
            /** @brief met les points � jour lors de la destruction du groupe
                @param Pion * : pion � l'origine de la mort du groupe */
            virtual void setPointOnDeath(Pion *);
            /** @brief met les points � jour lors de la fin de la partie */
            virtual void setPointOnEnd(void){ }
            virtual ~Groupe(){}
        protected :
            /** @brief Nombre de pions contenu dans le groupe */
            int nbPion;
            /** @brief Type du groupe */
            int type;
            /** @brief Libert� du groupe */
            int liberte;
            /** @brief �quipe poss�dant le groupe */
            Equipe * equipe;
            typedef std::list<Pion *> ListePion;
            ListePion listePion;
            friend class Plateau;
        };
    }
}

#endif // GROUPE_H
