#ifndef JEUX_H
#define JEUX_H

#include <irrlicht/irrlicht.h>

#include "eventrecever.h"

namespace LD
{
    class Map;
    struct Preferances;

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

        //TODO changeCamera();
        //TODO changeCurseur();
        //TODO changeGui();
        /** @brief détecte les autres évènements */
        void detectAutreEvent(void);
    private :
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

        friend class EventRecever;
    };
}
#endif // JEUX_H
