#include<iostream>

#include <irrlicht/irrlicht.h>

#include "jeux.h"
#include "map/diapo2d.h"
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
    LD::Jeux jeux(800,600, L"Last Dungeon - ");
    const char * tabImage[] = {"ressources/intro1.png", "ressources/intro2.png", NULL};
    LD::Diapo2D * diapo = new LD::Diapo2D(&jeux, tabImage, "applaudi-foule.wav", 10, 1, true);
    diapo->start();
    jeux.start();
    return 0;
}
