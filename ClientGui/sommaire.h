#ifndef SOMMAIRE_H
#define SOMMAIRE_H

#include "map/menu.h"
#include "soundmanager.h"

namespace LD
{
    class Jeux;
    /** @brief Permet de changer de map */
    class Sommaire
    {
    public:
        /** @brief construit le sommaire
          @param Jeux * jeux : pointeur vers le jeux */
        Sommaire(Jeux * jeux);
        ~Sommaire();
        /** @brief Prochaine map à charger */
        int next;
        /** @brief charge la prochaine map et détruit l'ancienne */
        void change(void);
        /** @brief pointeur vers le jeux */
        Jeux * jeux;
        /** @brief pointeur sur le menu de jeux */
        Menu * menu;
        /** @brief indique si on est sur le menu ou non */
        bool menuActive;
        /** @brief envois un évènement au menu */
        inline bool eventMenu(const irr::SEvent event)
        {
            if(! menuActive)
                return false;
            return menu->onEvent(event);
        }
        /** @brief enregistre les sons et autres */
        SoundManager soundManager;
    };

    /** @brief défini les différentes Maps */
    namespace SOMMARY
    {
    /** @brief défini les différentes Maps
      @enum MENU : menu de jeux */
        enum{MENU=-1};
    }
}

#endif // SOMMAIRE_H
