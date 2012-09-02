#include "fenetrecreationsalon.h"

namespace LD
{
    FenetreCreationSalon::FenetreCreationSalon(irr::gui::IGUIEnvironment *gui, irr::u32 x, irr::u32 y)
        : gui(gui),
          fenetre(gui->addWindow(irr::core::rect<irr::s32>( (x-200)/2, (y-200)/2,(x+200)/2,(y+200)/2), true, L"Creation du salon")),
          nomSalon( gui->addEditBox(L"Venez jouer^^", irr::core::rect<irr::s32>(0,20,100,40), true, fenetre) ),
          password( gui->addEditBox(NULL, irr::core::rect<irr::s32>(0,50,100,70), true, fenetre) ),
          officiel(gui->addCheckBox(true, irr::core::rect<irr::s32>(0,60,20,80), fenetre)),
          joueurExterne(gui->addCheckBox(true, irr::core::rect<irr::s32>(0,80,10,90), fenetre)),
          joueurInterne(gui->addCheckBox(false, irr::core::rect<irr::s32>(0,100,10,110), fenetre)),
          boutonAnnuler(gui->addButton(irr::core::rect<irr::s32>( 0, 120, 50, 130), fenetre, -1, L"Annuler")),
          boutonValider(gui->addButton(irr::core::rect<irr::s32>( 70, 120, 120, 130), fenetre, -1, L"Valider"))
    {
        fenetre->getCloseButton()->remove();
    }

    FenetreCreationSalon::~FenetreCreationSalon()
    {
        boutonValider->remove();
        boutonAnnuler->remove();
        joueurInterne->remove();
        joueurExterne->remove();
        officiel->remove();
        password->remove();
        nomSalon->remove();
        fenetre->remove();
    }

    bool FenetreCreationSalon::onEvent(const  irr::SEvent & event)
    {
        if(event.EventType == irr::EET_GUI_EVENT)
        {
            if(event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
            {
                valider = (event.GUIEvent.Caller == boutonValider);
                return true;
            }
        }
        return false;
    }
}
