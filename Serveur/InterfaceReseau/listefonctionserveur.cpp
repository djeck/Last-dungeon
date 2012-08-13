#include <iostream>

#include "listefonctionserveur.h"

namespace LD
{
    extern const FctTraitement LISTE_FCT[] = {&arretProgrammeServeur, &decoClient};

    bool arretProgrammeServeur(Instruction &, ParamTraitement & p)
    {
        p.running = false;
        return true;
    }


    bool decoClient(Instruction &, ParamTraitement &)
    {
        return true;
    }
}
