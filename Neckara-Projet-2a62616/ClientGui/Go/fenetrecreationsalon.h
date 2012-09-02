#ifndef FENETRECREATIONSALON_H
#define FENETRECREATIONSALON_H

#include <irrlicht/irrlicht.h>
#include <string>

namespace LD
{
/** @brief affiche la fenetre permettant la cr�ation du salon */
    class FenetreCreationSalon
    {
    public:
        /** @brief Affiche la fenetre dans une fen�tre principale de dimension x et y pixels */
        FenetreCreationSalon(irr::gui::IGUIEnvironment * gui, irr::u32 x, irr::u32 y);
        ~FenetreCreationSalon();
        /** @brief Retourne true si le joueur a valider la cr�ation d'un salon ou a cliqu� sur annul� */
        bool onEvent(const  irr::SEvent &);
        /** @brief Indique si la fenetre doit sa fermeture � une validation ou � une annulation */
        bool isValidate(void){ return valider; }
        /** @brief Permet d'obtenir le nom du salon */
        std::wstring getNomSalon(void){ return nomSalon->getText(); }
        /** @brief Permet d'obtenir le mot de passe */
        std::wstring getPassword(void){ return password->getText(); }
        /** @brief Permet de savoir si on veut un salon officiel ou non */
        bool isOfficiel(void){ return officiel->isChecked(); }
        /** @brief Permet de savoir si on accepte les joueurs externes ou non (dans le cas d'un salon non-officiel) */
        bool isJexterne(void){ return joueurExterne->isChecked(); }
        /** @brief Permet de savoir si on accepte les joueurs interne ou non (dans le cas d'un salon non-officiel) */
        bool isJInterne(void){ return joueurInterne->isChecked(); }
    protected :
        /** @brief GUI */
        irr::gui::IGUIEnvironment * gui;
        /** @brief fenetre */
        irr::gui::IGUIWindow * fenetre;
        /** @brief zone de texte pour le nom du salon */
        irr::gui::IGUIEditBox * nomSalon;
        /** @brief zone de texte pour le mot de passe */
        irr::gui::IGUIEditBox * password;
        /** @brief checkbox pour savoir si on va cr�er un salon officiel ou non*/
        irr::gui::IGUICheckBox * officiel;
        /** @brief checkbox pour savoir si on va accepter les autres joueurs (salon non officiel) */
        irr::gui::IGUICheckBox * joueurExterne;
        /** @brief checkbox pour savoir si on va accepter qu'un joueur joue plusieurs joueurs */
        irr::gui::IGUICheckBox * joueurInterne;
        /** @brief Bouton pour annuler */
        irr::gui::IGUIButton * boutonAnnuler;
        /** @brief Bouton pour valider */
        irr::gui::IGUIButton * boutonValider;
        /** @brief Indique si la fenetre doit sa fermeture � une validation ou � une annulation */
        bool valider;
    };
}
#endif // FENETRECREATIONSALON_H
