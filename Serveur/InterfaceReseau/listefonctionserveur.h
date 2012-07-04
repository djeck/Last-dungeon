#ifndef LISTEFONCTIONSERVEUR_H
#define LISTEFONCTIONSERVEUR_H

#include "listeinstruction.h"
#include "paramtraitement.h"

namespace LD
{
    /** @brief Arrête le programme côté serveur */
    bool arretProgrammeServeur(Instruction &i, ParamTraitement & p);



    typedef bool (*FctTraitement)(Instruction &, ParamTraitement &);
    extern const FctTraitement LISTE_FCT[];

}

#endif // LISTEFONCTIONSERVEUR_H
