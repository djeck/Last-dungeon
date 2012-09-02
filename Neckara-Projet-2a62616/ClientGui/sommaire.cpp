#include <iostream>
#include "sommaire.h"
#include "jeux.h"
#include "map/vulistesalon.h"
#include "map/salongo.h"

namespace LD
{
Sommaire::Sommaire(Jeux * jeux) : next(0), jeux(jeux), menu(NULL), menuActive(false)
    {
    }

    void Sommaire::change(void)
    {
        menuActive = false;
        switch(next)
        {
            case SOMMARY::MENU :
                if(! menu)
                {
                    menu = new Menu(jeux, &soundManager);
                    jeux->setMap(menu);
                }
                menu->setMenu();
                menuActive = true;
            break;
            case SOMMARY::GO :
                jeux->setMap(new VuListeSalon(jeux) );
            break;
            case SOMMARY::SALON_GO :
                jeux->setMap(new SalonGo(jeux) );
            break;
            default :
                std::cerr << "Fatal erreur, map inconnue" << std::endl;
                exit(1);
        }
        next = 0;
    }

    Sommaire::~Sommaire()
    {
        jeux->setMap(menu);
    }

    void Sommaire::closeMenu()
    {
        menu->hide();
        menuActive = false;
        if(jeux->getMap() != menu)
            jeux->setMap(NULL);
        else
            jeux->noMap();
    }
}
