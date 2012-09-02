#ifndef REGLE_H
#define REGLE_H

namespace LD
{
    namespace GO
    {
        class Pion;
    /** @brief class virtuelle pure représentant un effet dans le jeux de go */
        class VirtualEffet
        {
        public :
            VirtualEffet(VirtualEffet * suivant) : suivant(suivant){}
            VirtualEffet * getSuivant(void){ return suivant; }
            void setSuivant(VirtualEffet * suivant){ this->suivant = suivant; }
            /** @brief place l'effet au premier suivant NULL en parcourant la liste de l'effet */
            void setEffetAtEnd(VirtualEffet * effet);
            virtual ~VirtualEffet() = 0;
            /** @brief Permet de dupliquer un effet */
            virtual VirtualEffet * duplicate(void) = 0;
            /** @brief execute l'effet */
            virtual void execute(Pion *) = 0;
        protected :
            VirtualEffet * suivant;
        };
    }
}

#endif // REGLE_H
