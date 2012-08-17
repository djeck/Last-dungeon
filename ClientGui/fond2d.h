#ifndef FOND2D_H
#define FOND2D_H

#include<irrlicht/irrlicht.h>
#include "map.h"

namespace LD
{
/** @brief fond 2D simple composé uniquement d'une image 2D */
    class Fond2D : public Map
    {
    public:
        /** @brief créé le fond2D */
        Fond2D();
        bool onEvent(const irr::SEvent &event);
        //TODO design pattern politique pour les traitements ?
    };
}
#endif // FOND2D_H
