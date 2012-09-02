#ifndef UNIXWINDOWS_H
#define UNIXWINDOWS_H

#include <string>

namespace LD
{
    /** @brief Ajoute au chemin pass� en param�tre le symbole ad�quat : '\' pour les Unix, '/' pour windows
        @param std::string & chemin : chemin auquel ajout� le symbole
        @return std::string & : chemin une fois le symbole ajout� */
    inline
    std::string & symboleDossier(std::string & chemin)
    {
        return chemin += '\\'; // '/' pour Unix
    }
}

#endif // UNIXWINDOWS_H
