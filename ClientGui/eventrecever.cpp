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
        return ! ( jeux->m_map ? jeux->m_map->onEvent(event) : true );
        /* && (jeux->gui)?jeux->gui->onEvent(event) ) : true */ ;
    }
}
