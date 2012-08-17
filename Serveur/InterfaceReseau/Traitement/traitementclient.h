#ifndef TRAITEMENTCLIENT_H
#define TRAITEMENTCLIENT_H

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
            class Client
            {
            public :
                    unsigned int getAttente();
                    const std::string & getMessage();
                    inline bool isBonPort(unsigned int droit ,sf::TcpSocket & socket);
                    int getMaxEchec();
            };
        }
    }
    typedef Traitement<TraitementP::Log::Default, TraitementP::Mode::Client> TraitementClient;
}
#include "traitementclient.inline"

#endif // TRAITEMENTCLIENT_H
