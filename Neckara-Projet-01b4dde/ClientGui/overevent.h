#ifndef OVEREVENT_H
#define OVEREVENT_H

#include "irrlicht/irrlicht.h"

namespace LD
{
/** @brief Classe dont toutes les fenêtres ou objets s'appropriant le focus d'une fenêtre ou objet père doit hériter.
  l'utilisation se fait ainsi :
  if(overEvent)
    return overEvent->onEvent(event);
  */
    class OverEvent
    {
    public:
        OverEvent();

        virtual bool onEvent(const irr::SEvent &) = 0;
        virtual ~OverEvent(){}
    };
}
#endif // OVEREVENT_H
