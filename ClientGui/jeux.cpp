#include <cstdio>
#include <iostream>
#include <windows.h> //windows


#include "jeux.h"
#include "preferances.h"
#include "map.h"
#include "sommaire.h"


namespace LD
{

    Jeux::Jeux(irr::u32 x, irr::u32 y, const wchar_t * titre) :
        //TODO voir pour la vsync (avant-dernier argument), true ou false ?
        x(x),
        y(y),
        device(irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d<irr::u32>(x,y), 32, false, true, false, 0) ),
        driver(device->getVideoDriver() ),
        sceneManager(device->getSceneManager() ),
        event(this),
        m_map(NULL),
        preferances(new Preferances() ),
        gui( device->getGUIEnvironment() ),
        sommaire(new Sommaire(this) )
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

        //Windows
        HANDLE hProcess= FindWindow(0,newTitre);
        HICON hIcon = LoadIcon( GetModuleHandle(NULL),  MAKEINTRESOURCE(1) );
        SendMessage( (HWND)hProcess,WM_SETICON,ICON_BIG, (LPARAM)hIcon);// Set big icon (ALT+TAB)
        SendMessage( (HWND)hProcess,WM_SETICON,ICON_BIG, (LPARAM)hIcon);// Set little icon (titlebar)

        delete [] newTitre;
        newTitre = NULL;
    }


    Jeux::~Jeux()
    {
        delete preferances;
        preferances = NULL;
        delete sommaire;
        sommaire = NULL;
        if(m_map)
            delete(m_map);
        m_map = NULL;
        device->drop();
    }


    void Jeux::start(void)
    {
        while (device->run()) {
            //TODO limiter le fps
            detectAutreEvent();
            driver->beginScene(true,true,irr::video::SColor(255,255,255,255));    // fond blanc
            sceneManager->drawAll();                    // calcule le rendu
            if(m_map)
                m_map->draw();
            gui->drawAll();
            driver->endScene();
        }
    }


    void Jeux::setMap(Map * map)
    {
        if(m_map == map)
            return;
        if(m_map)
            delete m_map;
        m_map = map;
    }

    void Jeux::detectAutreEvent()
    {
        if(sommaire->next)
            sommaire->change();
        // Serveur

        //fin timer
    }

    bool Jeux::eventMenu(const irr::SEvent event)
    {
        return sommaire->eventMenu(event);
    }
}
