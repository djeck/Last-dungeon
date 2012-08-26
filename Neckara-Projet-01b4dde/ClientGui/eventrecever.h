#ifndef EVENTRECEVER_H
#define EVENTRECEVER_H

#include <irrlicht/irrlicht.h>

namespace LD
{
    class Jeux;

    class EventRecever : public irr::IEventReceiver
    {
    public:
        /** @param Jeux * jeux : instance de jeux qui a créé EventRecever */
        EventRecever(Jeux * jeux);
        /** @brief Capte les évènements
            @param const irr::SEvent &event : évènement reçu */
        bool OnEvent(const irr::SEvent &event);
    private :
        /** @brief createur */
        Jeux * jeux;
    };
}
#endif // EVENTRECEVER_H
