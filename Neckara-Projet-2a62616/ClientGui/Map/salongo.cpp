#include <iostream>
#include "salongo.h"
#include "../jeux.h"

namespace LD
{
    SalonGo::SalonGo(Jeux * jeux) : Map(jeux),
        boutonJouer(jeux->getGUI()->addButton(irr::core::rect<irr::s32>(jeux->getX() - 10 - 40, 10, jeux->getX() - 10, 10 + 20), NULL, -1, L"Jouer"))
    {
    }

    SalonGo::~SalonGo()
    {
        boutonJouer->remove();
    }

    bool SalonGo::onEvent(const irr::SEvent &event)
    {
        return false;
    }

    void SalonGo::draw(void)
    {

    }
}
