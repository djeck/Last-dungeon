#include <iostream>
#include "boutonquitter.h"

namespace LD
{
    BoutonQuitter::BoutonQuitter(Jeux * jeux) :
        jeux(jeux), image(jeux->getDriver()->getTexture("ressources/BoutonQuitter.png")),
        imageGUI(NULL)
    {
    }


    void BoutonQuitter::show(const irr::core::vector2d<int> & position, irr::gui::IGUIElement * parent)
    {
        this->parent = parent;
        this->position = position;
        this->position.X -= image->getSize().Width;
        imageGUI = jeux->getGUI()->addImage(image, this->position, true, parent);
        //imageGUI->remove();
        fermeture = false;
    }

    void BoutonQuitter::hide()
    {
        imageGUI->remove();
    }

    bool BoutonQuitter::onEvent(const irr::SEvent & event)
    {
        if(event.EventType != irr::EET_MOUSE_INPUT_EVENT)
            return false;
        irr::core::vector2d<irr::s32> x(event.MouseInput.X, event.MouseInput.Y);
        if(! imageGUI->isPointInside( x ))
        {
            if(event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP)
                pressed = false;
            return false;
        }
        if(pressed && event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP)
        {
            fermeture = true;
            return true;
        }
        if(event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN)
        {
            pressed = true;
            return true;
        }
        return false;
    }

    BoutonQuitter::~BoutonQuitter()
    {
        //on a besoin de rien supprimer, car la texture sera utilisé partout dans le jeux
    }
}
