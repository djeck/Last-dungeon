#include <iostream>

#include "eventrecever.h"
#include "jeux.h"
#include "map.h"

namespace LD
{
    EventRecever::EventRecever(Jeux * jeux) : jeux(jeux)
        {
        }

    bool EventRecever::OnEvent(const irr::SEvent &event)
    {
        bool absorb = true;
        if( jeux->eventMenu(event) )
                return true;
        if(jeux->m_map)
            absorb = jeux->m_map->onEvent(event);
        return absorb;
    }
}
