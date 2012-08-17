#ifndef LISTENERADMIN_H
#define LISTENERADMIN_H

#include <SFML/Network.hpp>

#include "listener.h"

#include "../Traitement/traitementadmin.h"
#include "../listeinstruction.h"


namespace LD
{

    namespace ListenerP
    {
        namespace Log
        {
            class Default
            {
            public :
                inline void startEcoute(sf::Socket::Status & status);
                inline void coBanni();
                inline void filtrageOk();
                inline void close();

            };
        }
        namespace Traitement
        {

            class Param
            {
            public :
                typedef TraitementAdmin Cible;
                inline void entrer(void);
                inline void sortir(void);
                inline void traiter(sf::Packet &, Joueur &, TraitementAdmin & );
            private :
                    sf::Mutex mutex;
            };
        }


        namespace Bloque
        {

            class NoBloque
            {
            public :
                inline bool isBloque(sf::TcpSocket * socket, bool bloque);
            };
        }

        namespace Close
        {

            class NoClose
            {
            public :
                inline bool boucle(bool fermer);

                inline bool boucle(bool fermer, bool running);

                inline void wait();
            };
        }
    }
    typedef Listener<ListenerP::Traitement::Param, ListenerP::Log::Default, ListenerP::Bloque::NoBloque, ListenerP::Close::NoClose> ListenerAdmin;
}

#include "listeneradmin.inline"

#endif // LISTENERADMIN_H
