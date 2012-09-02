#include <iostream>
#include <algorithm>
#include "fenetreconnexion.h"
#include "../ComposantFenetre/boutonquitter.h"

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
        password(NULL),
        bQuitter(jeux),
        erreur(NULL)
    {
    }

    void FenetreConnexion::show()
    {
        fermeture = false;
        fondGUI = jeux->getGUI()->addImage(fond, irr::core::vector2d<int>(x,y) );
        login = jeux->getGUI()->addEditBox(
                    NULL, irr::core::rect<irr::s32>(120,25,120+150,25+25), true, fondGUI);
        password = jeux->getGUI()->addEditBox(
                    NULL, irr::core::rect<irr::s32>(120,25+45,120+150,25+45+25), true, fondGUI);
        bQuitter.show(irr::core::vector2d<irr::s32>(tailleFond.Width - 0,0), fondGUI);
        password->setPasswordBox(true);
        jeux->getGUI()->setFocus(login);
        boutonValider = jeux->getGUI()->addButton(irr::core::rect<irr::s32>( (tailleFond.Width - 200)/2, tailleFond.Height - 20 - 20, (tailleFond.Width + 200)/2, tailleFond.Height - 20),
                                                  fondGUI, -1, L"Valider");
    }
    void FenetreConnexion::hide()
    {
        password->remove();
        login->remove();
        boutonValider->remove();
        fondGUI->remove();
    }

    FenetreConnexion::~FenetreConnexion()
    {
        jeux->getDriver()->removeTexture(fond);
    }

    bool FenetreConnexion::onEvent(const irr::SEvent & event)
    {
        if(erreur)
        {
            if(event.EventType == irr::EET_GUI_EVENT && event.GUIEvent.EventType == irr::gui::EGET_MESSAGEBOX_OK)
            {
                erreur = NULL;
                return true;
            }
            if(event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_RETURN && ! event.KeyInput.PressedDown)
            {
                erreur->remove();
                erreur = NULL;
                return true;
            }
            return false;
        }


        if(bQuitter.onEvent(event))
        {
            if( bQuitter.getFermeture() )
            {
                bQuitter.hide();
                hide();
                fermeture = true;
            }
            return true;
        }
        if(event.EventType == irr::EET_GUI_EVENT && event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
        {
            connexion();
        }

        if(event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.Key == irr::KEY_RETURN && ! event.KeyInput.PressedDown)
        {
            if(jeux->getGUI()->hasFocus(login) )
                jeux->getGUI()->setFocus(password);
            else
                connexion();//clique bouton
            return true;
        }
        if(event.EventType == irr::EET_MOUSE_INPUT_EVENT)
        {
            if(event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP )
                deplacement = false;
            else if(deplacement)
            {
                irr::u32 tmpX = (event.MouseInput.X > 0)?event.MouseInput.X:0;
                if(tmpX > jeux->getX())
                    tmpX = jeux->getX();
                irr::u32 tmpY = (event.MouseInput.Y > 0)?event.MouseInput.Y:0;
                if(tmpY > jeux->getY())
                    tmpY = jeux->getY();
                deplacementX = tmpX - deplacementX;
                deplacementY = tmpY - deplacementY;
                x += deplacementX;
                y += deplacementY;
                irr::core::vector2d<irr::s32> deplaRelatif(deplacementX, deplacementY);
                fondGUI->move( deplaRelatif );
                deplacementX = tmpX;
                deplacementY = tmpY;
                return true;
            }
            else if(! fondGUI->isPointInside(irr::core::vector2d<irr::s32>(event.MouseInput.X, event.MouseInput.Y) ) )
            {
                return true;
            }
            else if(boutonValider->isPointInside(irr::core::vector2d<irr::s32>(event.MouseInput.X,event.MouseInput.Y)))
            {
                return false;
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

    void FenetreConnexion::connexion(void)
    {
        std::wstring tmp = login->getText();
        std::string login( tmp.size(), ' ');
        std::copy(tmp.begin(), tmp.end(), login.begin() );

        tmp = password->getText();
        std::string password( tmp.size(), ' ');
        std::copy(tmp.begin(), tmp.end(), password.begin() );
        std::wstring msgErreur = L"";
        if(login == "" || password == "")
            msgErreur = L"Vous devez remplir les champs login et password";
        else
            msgErreur = L"Serveur indisponible : la partie serveur n'a pas encore ete cree !";
        if(msgErreur != L"")
        {
            erreur = jeux->getGUI()->addMessageBox(L"Erreur", msgErreur.c_str(), true);
            erreur->getCloseButton()->remove();
        }



        //connexion au serveur
    }
}
