#ifndef VIRTUALTRAITEMENT_H
#define VIRTUALTRAITEMENT_H

#include "../listeinstruction.h"

namespace LD
{
    /** @brief Classe virtuelle pure, se charge d'appeler la fonction permettant de traiter les instructions reçues. */
    class VirtualTraitement
    {
    public:
        VirtualTraitement();
        virtual ~VirtualTraitement();

        /** @brief traite une instruction*/
        virtual void traiterInstruction(Instruction & instruction) = 0;

        /** @brief traite uen instruction */
        virtual void traiter(void) = 0;
    };
}
#endif // VIRTUALTRAITEMENT_H
