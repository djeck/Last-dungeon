#include <iostream>
#include "fenetreconnexion.h"

namespace LD
{
    FenetreConnexion::FenetreConnexion(Jeux * jeux) :
        jeux(jeux),
        fond(jeux->getDriver()->getTexture("ressources/fondConnexion.png")),
        fondGUI(NULL),
        tailleFond( fond->getSize() ),
        x( (jeux->getX() - tailleFond.Width)/2),
        y( (jeux->getY() - tailleFond.Height)/2),
        deplacement(false),
        login(NULL),
        password(NULL)
    {
    }

    void FenetreConnexion::show()
    {
        fondGUI = jeux->getGUI()->addImage(fond, irr::core::vector2d<int>(x,y) );
        irr::gui::IGUIFont *font = jeux->getGUI()->getFont("ressources/fontlucida.png");
        login = jeux->getGUI()->addEditBox(
                    NULL, irr::core::rect<irr::s32>(x+120,y+25,x+120+150,y+25+25));
        password = jeux->getGUI()->addEditBox(
                    NULL, irr::core::rect<irr::s32>(x+120,y+25+45,x+120+150,y+25+45+25));
        password->setPasswordBox(true);
        login->setOverrideFont(font);
        jeux->getGUI()->setFocus(login);
        password->setOverrideFont(font);
    }

    FenetreConnexion::~FenetreConnexion()
    {
        jeux->getDriver()->removeTexture(fond);
    }

    bool FenetreConnexion::onEvent(const irr::SEvent & event)
    {
        if(event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_RETURN)
        {
            if(jeux->getGUI()->hasFocus(login) )
                jeux->getGUI()->setFocus(password);
            else
                ;//clique bouton
            return true;
        }
        if(event.EventType == irr::EET_MOUSE_INPUT_EVENT)
        {
            if(event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP )
                deplacement = false;
            else if(deplacement)
            {
                deplacementX = event.MouseInput.X - deplacementX;
                deplacementY = event.MouseInput.Y - deplacementY;
                x += deplacementX;
                y += deplacementY;
                irr::core::vector2d<irr::s32> deplaRelatif(deplacementX, deplacementY);
                fondGUI->move( deplaRelatif );
                login->move( deplaRelatif );
                password->move( deplaRelatif );
                deplacementX = event.MouseInput.X;
                deplacementY = event.MouseInput.Y;
                return true;
            }
            else if(event.MouseInput.X < x ||
                event.MouseInput.Y < y ||
                event.MouseInput.X > x + tailleFond.Width ||
                event.MouseInput.Y > y + tailleFond.Height) //si en dehors
            {
                return true;
            }
            else if( event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN)
            {
                if(login->isPointInside(irr::core::vector2d<irr::s32>(event.MouseInput.X, event.MouseInput.Y)))
                    return false;
                if(password->isPointInside(irr::core::vector2d<irr::s32>(event.MouseInput.X, event.MouseInput.Y)))
                    return false;
                deplacement = true;
                deplacementX = event.MouseInput.X;
                deplacementY = event.MouseInput.Y;
            }
        }

        return false;
    }
}
