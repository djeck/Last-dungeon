#ifndef LISTENER_H
#define LISTENER_H

#include <SFML/Network.hpp>
#include <list>

#include "virtuallistener.h"

#include "../joueur.h"
#include "../../../Communs/requetebdd.h"
//#include "../../../Communs/Param.h"
#include "../../../Communs/enumTraitement.h"
#include "../listeinstruction.h"

namespace LD
{
    /** @brief  Classe pour écouter un port. Toutes les autres classes listener ne seront que des typedef de cette classe.
        Logs : défini les logs à effectuer. Une méthode vide pour ne rien faire.
        ModeTraitement : détermine le mode de traitement des informations reçues.
        BloqueConnexion : défini le blocages des connexions entrantes.
        CloseConnexion : défini le blocage du listener.
        Les méthodes contenues dans ces classes doivent être inlines. */
    template<typename ModeTraitement, typename Logs, typename BloqueConnexion, typename CloseConnexion>
    class Listener : VirtualListener
    {
    public :
        /** @brief constuit une instance qui va écouter un port
          Rq : il serait plus pratique de crééer une structure regroupant tous ces paramètres.
            @param unsigned int port : port d'écoute
            @param const bool & running : on arrête le serveur quand il passe à true
            @param int nbThread : nombre de thread pouvant accéder aux informations d'un joueur en lecture simultanément
            @param int nbSec : nombre de secondes maximums d'attentes entre l'instruction d'arrêt et l'arrêt du listener (quand aucune donnée est reçue pendant ce temps).
            0 pour ne pas mettre de durée maximums (l'arrêt sera réellement pris en compte lorsque le serveur recevra un paquet).
            Permet de construire le temps de timeout.
            @param  const bool & isCloseListener : lorsqu'il passe à true, on "suspent" le Listener
            @param const bool & isBloqueEntrant : si on bloque ou non les connexions entrantes
            @param ListeInstruction * listeInstruction liste d'instruction à utiliser */
        Listener(unsigned int port, bool & running, int nbThread, int nbSec, const bool & isCloseListener,
                 const bool & isBloqueEntrant, typename ModeTraitement::Cible & cible);

        /** @brief démarre l'écoute du serveur */
        virtual void start(void);

        /** @brief enlève un joueur de la liste des joueurs ayant établie une connexion avec le serveur
           @param Joueur & : joueur à enlever de la liste */
        virtual void delSocket(Joueur &);


        virtual ~Listener();
    protected :
            /** @brief classe en charge des logs */
            Logs logs;

            /** @brief classe en charge des zones critiques */
            ModeTraitement mode;

            /** @brief classe en charge du blocage des connexions entrantes */
            BloqueConnexion bloqueCo;

            /** @brief classe en charge du blocage du listener */
            CloseConnexion closeCo;

            /** @brief temps de timeout */
            sf::Time timeout;

            /** @brief ferme le serveur */
            void close(void);

            /** @brief port d'écoute */
            const unsigned int port;

            /** @brief quand running passe à false, on éteint le serveur */
            bool & running;

            /** @brief liste d'écoute */
            ListeSocket listeSocket;

            /** @brief Nombre de thread maximum */
            const int nbThread;

            /** @brief Pointeur sur le selector en cours */
            sf::SocketSelector * selector;

            /** @ brief lorsqu'il passe à true, on "suspent" le Listener*/
            const bool & isCloseListener;

            /** @brief si on bloque ou non les connexions entrantes */
            const bool & isBloqueEntrant;

            /** @brief objet à utiliser pour envoyer les instructions */
            typename ModeTraitement::Cible & cible;

            /** @brief démarre l'écoute du serveur
            @param sf::TcpListener & : socket pour les connexions entrantes
            @param sf::SocketSelector & selector : selecteur de socket */
            virtual void startEcoute(sf::TcpListener & listener, sf::SocketSelector & selector);

            /** @brief filtre les connexions entrantes
            @param sf::TcpListener & : socket pour les connexions entrantes */
            virtual void filtrageEntrant(sf::TcpListener & listener);


            /** @brief Ajoute un socket à la liste d'écoute
                @brief sf::TcpSocket & s : socket à ajouter */
            virtual void addSocket(sf::TcpSocket & s);
    };
}

#include "listener.tpp"

#endif // LISTENER_H
