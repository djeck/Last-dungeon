#ifndef MAP_H
#define MAP_H

#include<irrlicht/irrlicht.h>

namespace LD
{
/** @brief d�termine le fond de la fen�tre, ce qui est derri�re la "GUI" */
    class Map : irr::IEventReceiver
    {
    public:
        Map();
        /** @brief traitement des �v�nements re�us */
        virtual bool onEvent(const irr::SEvent &event) = 0;
        /** @brief dessine */
        virtual void draw(void) = 0;
        virtual ~Map(){}
    };
}

#endif // MAP_H
