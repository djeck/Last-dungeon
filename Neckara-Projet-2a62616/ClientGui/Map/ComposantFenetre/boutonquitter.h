#ifndef BOUTONQUITTER_H
#define BOUTONQUITTER_H

#include "../../jeux.h"

namespace LD
{
/** @brief Affiche un bouton "quitter" */
    class BoutonQuitter
    {
    public:
        /** @brief  Rq : on peut mettre une image "bouton pressé" */
        BoutonQuitter(Jeux * jeux);
        /** @brief affiche le bouton /!\ La position est celle du coin en haut à droite */
        void show(const irr::core::vector2d<int> & position, irr::gui::IGUIElement * parent);
        /** @brief enlève le bouton */
        void hide(void);
        bool onEvent(const irr::SEvent & event);
        ~BoutonQuitter();
    private :
        Jeux * jeux;
        irr::gui::IGUIElement * parent;
        irr::core::vector2d<int> position;
        /** @brief Texture du bouton */
        irr::video::ITexture *image;
        /** @brief Image du bonton chargé dans la GUI */
        irr::gui::IGUIImage * imageGUI;
        /** @brief indique si le bouton est pressé */
        bool pressed;
        /** @brief indique si on a reçu un évènement "quitter" */
        bool fermeture;
    public :
        inline bool getFermeture(void){ return fermeture; }
    };
}
#endif // BOUTONQUITTER_H
