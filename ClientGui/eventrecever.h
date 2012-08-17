#ifndef EVENTRECEVER_H
#define EVENTRECEVER_H

#include <irrlicht/irrlicht.h>

namespace LD
{
    class Jeux;

    class EventRecever : public irr::IEventReceiver
    {
    public:
        /** @param Jeux * jeux : instance de jeux qui a cr�� EventRecever */
        EventRecever(Jeux * jeux);
        /** @brief Capte les �v�nements
            @param const irr::SEvent &event : �v�nement re�u */
        bool OnEvent(const irr::SEvent &event);
    private :
        /** @brief createur */
        Jeux * jeux;
    };
}
#endif // EVENTRECEVER_H
