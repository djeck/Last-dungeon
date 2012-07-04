#ifndef PARAMTRAITEMENT_H
#define PARAMTRAITEMENT_H

#include "listeinstruction.h"

namespace LD
{


    /*
    Enum chaine :
    enum{.., .., MAX};
    enum{DeB=MAX, .., .., .. , MAX};
    */


    struct ParamTraitement
    {
        /** @ brief construit un paramètre
            @param bool & running : quand il passe à false, on arrête le programme du côté du serveur */
        ParamTraitement(bool & running);
        /** @brief quand il passe à false, on arrête le programme du côté du serveur */
        bool & running;
    };
}

#endif // PARAMTRAITEMENT_H
