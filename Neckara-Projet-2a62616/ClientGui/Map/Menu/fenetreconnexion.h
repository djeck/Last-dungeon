#ifndef FENETRECONNEXION_H
#define FENETRECONNEXION_H


#include "../../jeux.h"
#include "../../overevent.h"
#include "../ComposantFenetre/boutonquitter.h"

namespace LD
{
    class FenetreConnexion : public OverEvent
    {
    public:
        FenetreConnexion(Jeux * jeux);
        ~FenetreConnexion();
        /** @brief affiche la fenetre de connexion */
        void show(void);
        /** @ brief ferme la fenetre de connexion */
        void hide(void);
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
        /** @brief Bouton de fermeture */
        BoutonQuitter bQuitter;
        /** @brief Bouton valider */
        irr::gui::IGUIButton * boutonValider;
        /** @brief On tente de se connecter ! \o/ */
        void connexion(void);
        /** @brief fenetre d'erreur */
        irr::gui::IGUIWindow * erreur;
    };
}

#endif // FENETRECONNEXION_H
