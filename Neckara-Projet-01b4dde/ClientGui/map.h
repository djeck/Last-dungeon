#ifndef MAP_H
#define MAP_H

#include<irrlicht/irrlicht.h>

namespace LD
{
/** @brief détermine le fond de la fenêtre, ce qui est derrière la "GUI" */
    class Map
    {
    public:
        Map();
        /** @brief traitement des évènements reçus */
        virtual bool onEvent(const irr::SEvent &event) = 0;
        /** @brief dessine */
        virtual void draw(void) = 0;
        virtual ~Map(){}
    };
}

#endif // MAP_H
