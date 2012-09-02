#ifndef DIAPO2D_H
#define DIAPO2D_H

#include <SFML/Audio.hpp>
#include <irrlicht/irrlicht.h>

#include "../map.h"

namespace LD
{
    class Jeux;
/** @brief diaporama simple d'images. Il suffit d'attendre pour changer d'image ou d'appuyer sur une touche */
    class Diapo2D : public Map
    {
    public:
        /** @brief Construit un diaporama.
          @param irr::video::IVideoDriver * driver : driver.
            @param const char ** images : images à charger, le dernier élément doit valoir NULL
            @param char * musique : musique à mettre pour la diaporama
            @param int tmp = 1 : temps entre chaque diapo
            @param int tmpMin : temps minimum entre chaque diapo (transition par évènement)
            @param bool changeOnEvent : indique si un évènement peut permetre le changement d'image */
        Diapo2D(Jeux * jeux, const char ** images, const char * musique = NULL, int tmp = 1, int tmpMin = 1, bool changeOnEvent = false);
        /** @brief démarre le diaporama */
        void start(void);
        /** @brief traitement des évènements reçus */
        bool onEvent(const irr::SEvent &event);


        /** @brief dessine la diapo */
        void draw(void);

        ~Diapo2D();
    private :
        /** indique si un évènement peut permetre le changement d'image */
        bool changeOnEvent;
        /** @brief musique de fond pour le diaporama */
        sf::Music music;
        /** @brief tableau d'images à afficher */
        irr::video::ITexture **image;
        /** @brief image en cours */
        int imageCour;
        /** @brief nombres d'images */
        int nbImages;
        /** @brief taille de l'image en cours*/
        irr::core::dimension2d<irr::s32> taille;
        /** @brief Timer */
        sf::Clock clock;
        /** @brief temps minimum entre les diapos */
        int tpsMin;
        /** @brief passe à la diapo suivante */
        void changeDiapo(void);
        /** @brief temps maximum entre les diapos */
        int tpsMax;
    };
}

#endif // DIAPO2D_H
