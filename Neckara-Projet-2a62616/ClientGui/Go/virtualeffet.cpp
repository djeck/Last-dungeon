#include "virtualeffet.h"

namespace LD
{
    namespace GO
    {
        void VirtualEffet::setEffetAtEnd(VirtualEffet * effet)
        {
            VirtualEffet ** p = &suivant;
            while(*p)
                p = &( (*p)->suivant);
            *p = effet;
        }
    }
}
