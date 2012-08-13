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

int main(void)
{
    LD::Jeux jeux(800,600, L"Last Dungeon - ");
    LD::Fond2D * fond = new LD::Fond2D();
    jeux.setMap(fond);
    jeux.start();
    return 0;
}
