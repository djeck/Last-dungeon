#include "vulistesalon.h"
#include "../jeux.h"
#include "../sommaire.h"
#include "../go/fenetrecreationsalon.h"

namespace LD
{
    VuListeSalon::VuListeSalon(Jeux * jeux) : Map(jeux),
        boutonCreer(jeux->getGUI()->addButton(irr::core::rect<irr::s32>(jeux->getX() - 10 - 40, 10, jeux->getX() - 10, 10 + 20), NULL, -1, L"Creer")),
        fenCreatSalon(NULL)
    {

    }

    VuListeSalon::~VuListeSalon()
    {
        boutonCreer->remove();
    }

    void VuListeSalon::draw(void)
    {
        //TODO mettre fond
    }


    bool VuListeSalon::onEvent(const irr::SEvent &event)
    {
        if(fenCreatSalon)
        {
            if( fenCreatSalon->onEvent(event) )
            {
                if( fenCreatSalon->isValidate() )
                {
                    //créer le salon
                }
                delete fenCreatSalon;
                fenCreatSalon = NULL;
            }

            return false;
        }
        if(event.EventType == irr::EET_GUI_EVENT)
        {
            if(event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
            {
                if(event.GUIEvent.Caller == boutonCreer)
                {
                    fenCreatSalon = new FenetreCreationSalon( jeux->getGUI(), jeux->getX(), jeux->getY() );
                        //jeux->sommaire->next = SOMMARY::SALON_GO;
                }
            }
        }
        return false;
    }
}
