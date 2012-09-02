#ifndef BOUTONQUITTER_H
#define BOUTONQUITTER_H

#include "../../jeux.h"

namespace LD
{
/** @brief Affiche un bouton "quitter" */
    class BoutonQuitter
    {
    public:
        /** @brief  Rq : on peut mettre une image "bouton press�" */
        BoutonQuitter(Jeux * jeux);
        /** @brief affiche le bouton /!\ La position est celle du coin en haut � droite */
        void show(const irr::core::vector2d<int> & position, irr::gui::IGUIElement * parent);
        /** @brief enl�ve le bouton */
        void hide(void);
        bool onEvent(const irr::SEvent & event);
        ~BoutonQuitter();
    private :
        Jeux * jeux;
        irr::gui::IGUIElement * parent;
        irr::core::vector2d<int> position;
        /** @brief Texture du bouton */
        irr::video::ITexture *image;
        /** @brief Image du bonton charg� dans la GUI */
        irr::gui::IGUIImage * imageGUI;
        /** @brief indique si le bouton est press� */
        bool pressed;
        /** @brief indique si on a re�u un �v�nement "quitter" */
        bool fermeture;
    public :
        inline bool getFermeture(void){ return fermeture; }
    };
}
#endif // BOUTONQUITTER_H
