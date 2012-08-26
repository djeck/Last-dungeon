#include <iostream>
#include "sommaire.h"
#include "jeux.h"

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
            case -1 :
                if(! menu)
                {
                    menu = new Menu(jeux, &soundManager);
                    jeux->setMap(menu);
                }
                menu->setMenu();
                menuActive = true;
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
}
