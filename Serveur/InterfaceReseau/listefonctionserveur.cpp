#include "listefonctionserveur.h"

#include <iostream>

namespace LD
{
    extern const FctTraitement LISTE_FCT[] = {&arretProgrammeServeur};

    bool arretProgrammeServeur(Instruction &i, ParamTraitement & p)
    {
        p.running = false;
        return true;
    }

}
