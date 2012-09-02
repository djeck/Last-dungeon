#ifndef MAP_H
#define MAP_H

#include<irrlicht/irrlicht.h>

namespace LD
{
    class Jeux;
/** @brief détermine le fond de la fenêtre, ce qui est derrière la "GUI" */
    class Map
    {
    public:
        Map(Jeux * jeux) : jeux(jeux){}
        /** @brief traitement des évènements reçus */
        virtual bool onEvent(const irr::SEvent &event) = 0;
        /** @brief dessine */
        virtual void draw(void){}
        virtual ~Map(){}
    protected :
        Jeux * jeux;
    };
}

#endif // MAP_H
