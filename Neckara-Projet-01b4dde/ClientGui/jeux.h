#ifndef JEUX_H
#define JEUX_H

#include <irrlicht/irrlicht.h>

#include "eventrecever.h"

namespace LD
{
    class Map;
    struct Preferances;
    class Sommaire;

    /** @brief Classe permettant de lancer le jeux */
    class Jeux
    {
    public:
        /** @brief Initialise la fenêtre de jeux.
          @param irr::u32 x  : largeur de la fenêtre
          @param irr::u32 y : hauteur de la fenêtre
          @param const wchar_t * titre : titre de la fenetre à laquelle sera concaténée la version */
        Jeux(irr::u32 x, irr::u32 y, const wchar_t * titre);

        virtual ~Jeux();

        /** @brief Permet de changer la map */
        void setMap(Map *);

        /** @brief Démarre le Jeux.
            /!\ Avant de lancer cette méthode, pensez bien à définir les actions clavier et souris */
        void start(void);

        /** @brief Permet d'obtenir le driver */
        inline irr::video::IVideoDriver * getDriver(void){ return driver; }
        /** @brief permet d'obtenir la GUI */
        inline irr::gui::IGUIEnvironment * getGUI(void){ return gui; }
        /** @brief envois un évènement au menu */
        bool eventMenu(const irr::SEvent event);
        //TODO changeCamera();
        //TODO changeCurseur();
        //TODO changeGui();
        inline irr::u32 getX(void){ return x; }
        inline irr::u32 getY(void){ return y; }

    private :
        /** @brief largeur de la fenetre */
        irr::u32 x;
        /** @brief hauteur de la fenetre */
        irr::u32 y;
        /** @brief détecte les autres évènements */
        void detectAutreEvent(void);
        /** @brief Heu... */
        irr::IrrlichtDevice *device;

        /** @brief driver */
        irr::video::IVideoDriver* driver;

        /** @brief sceneManager */
        irr::scene::ISceneManager *sceneManager;

        /** @brief reçoit les évents */
        EventRecever event;

        /** @brief fond */
        Map * m_map;

        /** @brief Preferances du joueur */
        Preferances * preferances;

        /** @brief gui */
        irr::gui::IGUIEnvironment * gui;
    public :
        /** @brief permet de changer de map */
        Sommaire * sommaire;
        /** @brief quitte le jeux */
        inline void quitter(void){ device->closeDevice(); }

        friend class EventRecever;
    };
}
#endif // JEUX_H
