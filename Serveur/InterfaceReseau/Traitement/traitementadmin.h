#ifndef TRAITEMENTADMIN_H
#define TRAITEMENTADMIN_H

#include "Traitement.h"

namespace LD
{
    namespace TraitementP
    {
        namespace Log
        {
            class Default
            {

            };
        }
        namespace Mode
        {
            class Admin
            {
            public :
                    unsigned int getAttente();
                    const std::string & getMessage();
                    inline bool isBonPort(unsigned int droit ,sf::TcpSocket & socket);
                    int getMaxEchec();
            };
        }
    }
    typedef Traitement<TraitementP::Log::Default, TraitementP::Mode::Admin> TraitementAdmin;
}
#include "traitementadmin.inline"
#endif // TRAITEMENTADMIN_H
