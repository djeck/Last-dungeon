#include <iostream>

#include "diapo2d.h"
#include "../jeux.h"
#include "../sommaire.h"

namespace LD
{
    Diapo2D::Diapo2D(Jeux * jeux, const char ** images, const char * musique, int tps, int tpsMin, bool changeOnEvent)
        : changeOnEvent(changeOnEvent), jeux(jeux), imageCour(-1), nbImages(0), tpsMin(tpsMin), tpsMax(tps)
    {
        if(musique)
        {
            music.openFromFile(musique);
            music.setLoop(true);
        }
        for(const char ** tmpImages = images; *tmpImages; ++tmpImages, ++nbImages);
        this->image = new irr::video::ITexture *[nbImages];
        for(int i = 0; i != nbImages; ++i)
            this->image[i] = jeux->getDriver()->getTexture(images[i]);
    }

    void Diapo2D::start(void)
    {
        changeDiapo();
        jeux->setMap(this);
        music.play();
    }

    void Diapo2D::draw(void)
    {
        if(tpsMax && clock.getElapsedTime().asSeconds() > tpsMax)
            changeDiapo();
        if(imageCour != -1)
        {
            jeux->getDriver()->draw2DImage(image[imageCour], irr::core::position2d<irr::s32>(0,0),
                                irr::core::rect<irr::s32>(0,0,taille.Width,taille.Height), 0,
                                irr::video::SColor(255, 255, 255, 255), true);
        }
    }

    Diapo2D::~Diapo2D()
    {
        for(int i = 0; i != nbImages; ++i)
        {
            jeux->getDriver()->removeTexture(image[i]);
        }
        delete [] image;
        image = NULL;

    }

    bool Diapo2D::onEvent(const irr::SEvent &event)
    {
        if(! changeOnEvent)
            return false;
        if(event.EventType != irr::EET_KEY_INPUT_EVENT && event.EventType != irr::EET_MOUSE_INPUT_EVENT)
            return false;
        if(event.EventType == irr::EET_KEY_INPUT_EVENT && ! event.KeyInput.PressedDown )
            return false;
        if(event.EventType == irr::EET_MOUSE_INPUT_EVENT && ( ! event.MouseInput.isRightPressed() &&  ! event.MouseInput.isLeftPressed() ) )
            return false;
        if(tpsMin && clock.getElapsedTime().asSeconds() < tpsMin)
            return true;
        changeDiapo();
        return true;
    }


    void Diapo2D::changeDiapo(void)
    {
        clock.restart();
        if(++imageCour == nbImages)
        {
            --imageCour;
            jeux->sommaire->next = SOMMARY::MENU;
        }
        taille = image[imageCour]->getSize();
    }
}
