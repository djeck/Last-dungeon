#ifndef LISTENERCLIENT_H
#define LISTENERCLIENT_H

#include <SFML/Network.hpp>

#include "listener.h"


namespace LD
{

    /** @brief paramètre des listeners */
    namespace ListenerP
    {

        /** @brief défini les types de traitements */
        namespace Traitement
        {

            class Liste
            {
            public :
                typedef ListeInstruction Cible;
                inline void entrer(void);
                inline void sortir(void);
                inline void traiter(sf::Packet &, Joueur &, ListeInstruction & );
            private :
                    sf::Mutex mutex;
            };
        }
        /** @brief défini les différents types de logs */
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
        /** @brief défini les types de blocages de connexion entrantes */
        namespace Bloque
        {
            class Default
            {
            public :
                inline bool isBloque(sf::TcpSocket * socket, bool bloque);
            };
        }
        /** @brief défini les types de fermeture de l'écoute */
        namespace Close
        {
            class Default
            {
            public :
                inline bool boucle(bool fermer);

                inline bool boucle(bool fermer, bool running);

                inline void wait();
            };
        }
    }
    typedef Listener<ListenerP::Traitement::Liste, ListenerP::Log::Default, ListenerP::Bloque::Default, ListenerP::Close::Default> ListenerClient;
}

#include "listenerclient.inline"

#endif // LISTENERCLIENT_H
