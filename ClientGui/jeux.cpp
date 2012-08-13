#include <cstdio>
#include <iostream>
#include "jeux.h"
#include "preferances.h"
#include "map.h"

namespace LD
{
    Jeux::Jeux(irr::u32 x, irr::u32 y, const wchar_t * titre) :
        //TODO voir pour la vsync (avant-dernier argument), true ou false ?
        device(irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(x,y), 32, false, true, false, 0) ),
        driver(device->getVideoDriver() ),
        sceneManager(device->getSceneManager() ),
        event(this),
        m_map(NULL),
        preferances(new Preferances() )
    {
        /* Ajout d'une caméra par défaut */
        sceneManager->addCameraSceneNode (0, irr::core::vector3df (0,0,0), irr::core::vector3df (5,0,0));

        /* Ajout de la reception d'event */
        device->setEventReceiver(&event);

        wchar_t * newTitre;
        //On préfère utiliser fwopen qui est plus rapide que std::wcout.
        FILE * fichier = fopen("version", "rb");
        if(fichier)
        {
            size_t tailleVersion(0);
            fread( (void *)&tailleVersion, sizeof(size_t), 1, fichier);
            size_t tailleTitre = wcslen(titre);
            tailleVersion++;
            newTitre = new wchar_t[tailleTitre + tailleVersion];
            wcscpy(newTitre, titre);
            wchar_t * version = newTitre + tailleTitre;
            fread( (void *)version, sizeof(wchar_t), tailleVersion, fichier);
            fclose(fichier);
        }
        else
        {
            const wchar_t * version = L"Version inconnue";
            std::cout << wcslen(titre) << "\n" << wcslen(version) << std::endl;
            size_t taille = wcslen(titre) + wcslen(version) + 1;
            newTitre = new wchar_t[taille];
            swprintf(newTitre, taille, L"%s%s", titre, version);
        }
        /* Titre de la fenetre */
        device->setWindowCaption(newTitre);
        delete newTitre;
        //TODO icône

    }


    Jeux::~Jeux()
    {
        device->drop();
    }


    void Jeux::start(void)
    {
        while (device->run()) {
            //TODO limiter le fps
            detectAutreEvent();

            driver->beginScene(true,true,irr::video::SColor(255,255,255,255));    // fond blanc
            sceneManager->drawAll();                    // calcule le rendu
            driver->endScene();                         // affiche le rendu
        }
    }


    void Jeux::setMap(Map * map)
    {
        if(m_map)
            delete m_map;
        m_map = map;
        //TODO : relier node
    }

    void Jeux::detectAutreEvent()
    {
        // Serveur

        //fin timer
    }
}
