#ifndef VIRTUALLISTENER_H
#define VIRTUALLISTENER_H

#include <SFML/Network.hpp>
#include <list>

#include "../joueur.h"


namespace LD
{
    /** @brief Liste de socket associé à un joueur */
    typedef std::list<Joueur *> ListeSocket;


    /** @brief  Classe virtuelle pure servant à définir l'interface pour l'utilisation des classes listener. */
    class VirtualListener
    {
    public :
        /** @brief constuit une instance qui va écouter un port */
        VirtualListener();

        /** @brief démarre l'écoute du serveur */
        virtual void start(void) = 0;

        /** @brief enlève un joueur de la liste des joueurs ayant établie une connexion avec le serveur
           @param Joueur & : joueur à enlever de la liste */
        virtual void delSocket(Joueur &) = 0;

        virtual ~VirtualListener() = 0;
    };
}
#endif // VIRTUALLISTENER_H
