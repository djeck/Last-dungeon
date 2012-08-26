#ifndef MENU_H
#define MENU_H

#include "../map.h"
#include "../soundmanager.h"
#include "Menu/fenetreconnexion.h"
#include "../overevent.h"

namespace LD
{
    class Jeux;
/** @brief menu du jeux */
    class Menu : public Map
    {
    public:
        Menu(Jeux * jeux, SoundManager * soundManager);
        ~Menu();
        /** @brief traitement des évènements reçus */
        bool onEvent(const irr::SEvent &);
        /** @brief dessine le fond */
        void draw(void);
        /** @brief met en place le menu */
        void setMenu(void);
    private :
        Jeux * jeux;
        /** @brief image de fond de menu */
        irr::video::ITexture *image;
        /** @brief taille de l'image*/
        irr::core::dimension2d<irr::s32> taille;
        /** @brief image de fond de menu */
        irr::video::ITexture *imageMenu;
        /** @brief image Menu mis dans la GUI */
        irr::gui::IGUIImage * imageMenuGUI;
        /** @brief boutons */
        irr::gui::IGUIButton ** bouton;
        /** @brief sons */
        SoundManager * soundManager;
        /** @brief son quand on clique sur un bouton */
        sf::Sound sonClique;
        /** @brief fenetre de connexion */
        FenetreConnexion fenetreConnexion;
        /** @brief indique si une fenetre est par-dessus le menu (ex : connexion, paramètres) */
        OverEvent * overEvent;
    };
}

#endif // MENU_H
