#ifndef UNIXWINDOWS_H
#define UNIXWINDOWS_H

#include <string>

namespace LD
{
    /** @brief Ajoute au chemin passé en paramètre le symbole adéquat : '\' pour les Unix, '/' pour windows
        @param std::string & chemin : chemin auquel ajouté le symbole
        @return std::string & : chemin une fois le symbole ajouté */
    inline
    std::string & symboleDossier(std::string & chemin)
    {
        return chemin += '\\'; // '/' pour Unix
    }
}

#endif // UNIXWINDOWS_H
