#ifndef MAP_H
#define MAP_H

#include<irrlicht/irrlicht.h>

namespace LD
{
    class Jeux;
/** @brief d�termine le fond de la fen�tre, ce qui est derri�re la "GUI" */
    class Map
    {
    public:
        Map(Jeux * jeux) : jeux(jeux){}
        /** @brief traitement des �v�nements re�us */
        virtual bool onEvent(const irr::SEvent &event) = 0;
        /** @brief dessine */
        virtual void draw(void){}
        virtual ~Map(){}
    protected :
        Jeux * jeux;
    };
}

#endif // MAP_H
