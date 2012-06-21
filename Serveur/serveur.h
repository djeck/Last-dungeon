#ifndef SERVEUR_H
#define SERVEUR_H

#include <SFML/Network.hpp>

namespace LD
{
    /** @brief défini le serveur */
    class Serveur
    {
    public:
        /** @brief Construit un serveur, lance le thread administrateur et les threads horaires */
        Serveur();

        /** @brief Démarre le serveur et les threads producteurs (lecture des flux de données) ainsi que les threads rédacteurs (traitement des données lues) */
        void start(void);

        // stop
    private :
            /** @brief ensemble des sockets voulant se connecter */
            sf::SocketSelector selector;

            /** @brief écoute les nouvelles connexions */
            sf::TcpListener listener;
    };
}
#endif // SERVEUR_H
