#ifndef FENETRECONNEXION_H
#define FENETRECONNEXION_H

#include "../../jeux.h"
#include "../../overevent.h"
namespace LD
{
    class FenetreConnexion : public OverEvent
    {
    public:
        FenetreConnexion(Jeux * jeux);
        ~FenetreConnexion();
        /** @brief affiche la fenetre de connexion */
        void show(void);
    private :
        Jeux * jeux;
        /** @brief image de fond */
        irr::video::ITexture *fond;
        /** @brief fond mis dans la GUI */
        irr::gui::IGUIImage * fondGUI;
        /** @brief taille du fond */
        irr::core::dimension2d<irr::s32> tailleFond;
        /** @brief position x de la fenetre */
        irr::s32 x;
        /** @brief position y de la fenetre */
        irr::s32 y;
        /** @brief indique si la fenetre est en deplacement */
        bool deplacement;
        /** @brief position X initiale de la souris lors d'un déplacement */
        irr::s32 deplacementX;
        /** @brief position Y initiale de la souris lors d'un déplacement */
        irr::s32 deplacementY;
        /** @brief zone de texte login */
        irr::gui::IGUIEditBox * login;
        /** @brief zone de texte password */
        irr::gui::IGUIEditBox * password;
        bool onEvent(const irr::SEvent &);
    };
}

#endif // FENETRECONNEXION_H
