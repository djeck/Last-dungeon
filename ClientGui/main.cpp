#include<iostream>

#include <irrlicht/irrlicht.h>
#include<iostream>

#include "jeux.h"
#include "fond2d.h"
/*
//  -> Ecrire le nom de la version
#include <cstdio>

FILE * fichier = fopen("version", "wb");
const wchar_t * version = L"Version Alpha 0";
size_t nbCaractere = wcslen(version);
fwrite( (void *)&nbCaractere, sizeof(size_t), 1, fichier);
fwrite( (void *)version , sizeof(wchar_t), wcslen(version) + 1, fichier);
fclose(fichier);
*/

#include "soundmanager.h"

int main(void)
{
    LD::SoundManager smanage;
    sf::Sound s(*smanage.addSon("toto", "ball.wav") );
    s.play();
    sf::Music * m = smanage.addMusic("titi", "applaudi-foule.wav");
    m->setLoop(true);
    m->play();

    LD::Jeux jeux(800,600, L"Last Dungeon - ");
    LD::Fond2D * fond = new LD::Fond2D();
    jeux.setMap(fond);
    jeux.start();
    return 0;
}
