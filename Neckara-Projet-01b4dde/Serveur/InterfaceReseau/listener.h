#ifndef LISTENER_H
#define LISTENER_H

#include "joueur.h"
#include "listeinstruction.h"

#include <list>
#include <SFML/Network.hpp>

namespace LD
{
    /** @brief Liste de socket associé à un joueur */
    typedef std::list<Joueur *> ListeSocket;

    class Listener
    {
    public:
        /** @brief constuit une instance qui va écouter un port
            @param unsigned int port : port d'écoute
            @param const bool & running : on arrête le serveur quand il passe à true
            @param ListeInstruction & listeInstruction : liste des instructions
            @param bool & coEntrants : on bloque les connexions entrantes lorsqu'il passe à true
            @param const bool &closeServeurClient : lorsqu'il passe à true, on ferme le serveur aux clients
            @param sf::Mutex &verrou : verrou permettant rendre l'accès au le serveur au client rapidement.
            @param const int nbThread : nombre de thread max.
             */
        Listener(unsigned int port, /* const */ bool & running, ListeInstruction & listeInstruction, bool & coEntrants
                                   , const bool &closeServeurClient, sf::Mutex &verrou, const int nbThread);
        ~Listener();

        /** @brief démarre l'écoute du serveur */
        void start(void);

        /** @brief enlève un joueur de la liste des joueurs ayant établie une connexion avec le serveur
           @param Joueur & : joueur à enlever de la liste */
        void delSocket(Joueur &);
    private :
            /** @brief liste d'écoute */
            ListeSocket listeSocket;

            /** @brief démarre l'écoute du serveur
            @param sf::TcpListener & : socket pour les connexions entrantes
            @param sf::SocketSelector & selector : selecteur de socket */
            void startEcoute(sf::TcpListener & listener, sf::SocketSelector & selector);


            /** @brief filtre les connexions entrantes
            @param sf::TcpListener & : socket pour les connexions entrantes */
            void filtrageEntrant(sf::TcpListener & listener);

            /** @brief Ajoute un socket à la liste d'écoute */
            void addSocket(sf::TcpSocket &);

            /** @brief permet l'accès unique à la liste d'écoute */
            sf::Mutex verrouListener;

            /** @brief Liste d'instruction */
            ListeInstruction & listeInstruction;


            /** @brief quand running passe à false, on éteint le serveur */
            /* const */ bool & running;
            /** @brief Bloque les connexions entrantes en cas de surchage du serveur */
            bool & coEntrants;
            /** @brief Bloque le serveur Joueur mais laisse la possibilité aux administrateurs de se connecter */
            const bool &closeServeurClient;
            /** @brief Bloque le thread listener */
            sf::Mutex &verrou;

            /** @brief port d'écoute */
            const unsigned int port;

            /** @brief ferme le serveur */
            void close(void);

            /** @brief Nombre de thread maximum */
            const int nbThread;

            /** @brief Pointeur sur le selector en cours */
            sf::SocketSelector * selector;
    };
}
#endif // LISTENER_H
