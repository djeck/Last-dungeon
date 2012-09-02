#include "socle.h"
#include "virtualeffet.h"

namespace LD
{
    namespace GO
    {
        bool Socle::setPion(Pion * pion)
        {
            if(this->pion)
                return false;
            this->pion = pion;
            executeEffet(pion);
            return true;
        }


        void Socle::executeEffet(Pion *pion)
        {
            VirtualEffet * effet = listeEffet;
            while (effet)
            {
                effet->execute(pion);
                effet = effet->getSuivant();
            }
        }
    }
}
