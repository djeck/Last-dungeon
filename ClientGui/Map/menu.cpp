#include <iostream>

#include "menu.h"
#include "../jeux.h"

namespace LD
{
    namespace BOUTON
    {
        enum{CONEXION, LIGNE, PVP, HORS_LIGNE, EDITEUR, PARAM, QUITTER};
    }
    Menu::Menu(Jeux * jeux, SoundManager * soundManager) :
        jeux(jeux),
        image(jeux->getDriver()->getTexture("ressources/menu.png")),
        taille(image->getSize()),
        imageMenu(jeux->getDriver()->getTexture("ressources/menu2.png")),
        imageMenuGUI(NULL),
        bouton(NULL),
        soundManager(soundManager),
        fenetreConnexion(jeux),
        overEvent(NULL)
    {
        sonClique.setBuffer(*soundManager->addSon("cliqueBouton", "ressources/ball.wav") );
    }

    void Menu::setMenu(void)
    {
        irr::s32 tailleBoutonX = 150;
        irr::s32 tailleBoutonY = 30;
        irr::s32 top =90;
        irr::s32 ecartBoutonY = 10;
        int nbBouton = 7;
        const wchar_t * texteBouton[] = {L"Se Connecter",
                                         L"Acceder au monde en ligne",
                                         L"PVP",
                                         L"Acceder au monde hors ligne",
                                         L"Editeur",
                                         L"Parametres",
                                         L"Quitter"};
        irr::core::dimension2d<irr::u32> tailleMenu = imageMenu->getSize();


        imageMenuGUI = jeux->getGUI()->addImage(imageMenu, irr::core::vector2d<int>( (jeux->getX() - tailleMenu.Width)/2,
                                                                                     (jeux->getY() - tailleMenu.Height)/2));
        irr::gui::IGUIFont *font = jeux->getGUI()->getFont("ressources/fontlucida.png");
        bouton = new irr::gui::IGUIButton * [nbBouton];


        for(int i=0; i!= nbBouton; ++i)
        {
            bouton[i] = jeux->getGUI()->addButton(irr::core::rect<irr::s32>( (tailleMenu.Width - tailleBoutonX)/2, top + i*(tailleBoutonY + ecartBoutonY),
                                                                 (tailleMenu.Width + tailleBoutonX)/2, top + i*(tailleBoutonY + ecartBoutonY) + tailleBoutonY),
                                      imageMenuGUI, -1, texteBouton[i]);
            bouton[i]->setOverrideFont(font);
        }
        //font->drop();
    }

    void Menu::draw(void)
    {
        jeux->getDriver()->draw2DImage(image, irr::core::position2d<irr::s32>(0,0),
                            irr::core::rect<irr::s32>(0,0,taille.Width,taille.Height), 0,
                            irr::video::SColor(255, 255, 255, 255), true);
    }

    Menu::~Menu(void)
    {
        if(bouton)
            delete [] bouton;
        bouton = NULL;
        jeux->getDriver()->removeTexture(image);
        jeux->getDriver()->removeTexture(imageMenu);
    }


    bool Menu::onEvent(const irr::SEvent &event)
    {
        if(overEvent)
        {
            return overEvent->onEvent(event);
        }

        if(event.EventType == irr::EET_GUI_EVENT && event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
        {
            sonClique.play();
            if(event.GUIEvent.Caller == bouton[BOUTON::QUITTER])
                jeux->quitter();
            if(event.GUIEvent.Caller == bouton[BOUTON::CONEXION])
            {
                fenetreConnexion.show();
                overEvent = &fenetreConnexion;
            }
            return true;
        }
        return false;
    }
}
