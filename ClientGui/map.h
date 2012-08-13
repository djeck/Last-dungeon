#ifndef MAP_H
#define MAP_H

#include<irrlicht/irrlicht.h>

namespace LD
{
/** @brief d�termine le fond de la fen�tre, ce qui est derri�re la "GUI" */
    class Map
    {
    public:
        Map();
        virtual bool onEvent(const irr::SEvent &event) = 0;
        virtual ~Map(){}
    };
}

#endif // MAP_H
