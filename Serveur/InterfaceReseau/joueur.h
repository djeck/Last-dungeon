#ifndef JOUEUR_H
#define JOUEUR_H


#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <semaphore.h>

#include "InfoJoueur.h"

namespace LD
{
    class Listener;

    /** @brief Représente un joueur connecté ou non */
    class Joueur
    {
    public:
        /** @brief Permet de créer un joueur
            @param ListeSocket & listeSocket : liste de socket du listener
            @param sf::TcpSocket & socket : socket du joueur
            @param int nbThread : nombre de thread maximum pouvant accéder aux informations du joueur en même temps */
        Joueur(Listener & listener, sf::TcpSocket & socket, int nbThread);

        /** @brief Déconnecte le joueur, si le joueur est connecté, enregistre les informations et le supprime des différentes listes de joueurs.
        Dans tout les cas, supprime le joueur de la liste des sockets du listener.
        @param  Joueur & : joueur à supprimer */
        static void deleteJoueur(Joueur &);

        /** @brief Envois un message au joueur
            @param sf::Packet & paquet : message à envoyer
            @return bool : retourne false si le joueur est en train de se déconnecter */
        bool sendMessage(sf::Packet & paquet);

        /** @brief incrémente le compteur, ie une nouvelle instruction est rajoutée */
        void operator++(void);
        /** @brief décrément le compteur, ie une nouvelle instruction a été créée */
        void operator--(void);


        /** @brief Retourne true si les deux joueurs sont les mêmes
            @param const Joueur & other : joueur pour la comparaison
            @return bool : true si les deux joueur sont identiques, false sinon */
        bool operator==(const Joueur & other);

    private :


            /** @brief Enregistre les données du joueur dans le BDD.
                Ne doit jamais être appeler en dehors de deleteJoueur */
            ~Joueur();


            /** @brief Permet de déconnecter le joueur */
            Listener & listener;

    public :
            /** @brief Socket du joueur */
            sf::TcpSocket & socket;
    private :
            /** @brief informations sur le joueur, est à NULL si le joueur n'est pas connecté */
            InfoJoueur * infoJoueur;

            /** @brief nombre d'instructions non traitées de ce joueur */
            int compteur;

            /** @brief Permet de garantir l'accès unique des opérations d'écritures sur le joueur */
            sf::Mutex ecriture;

            /** @brief Permet d'empêcher des opérations d'écritures concurentes à des opérations de lecture sur le joueur */
            sem_t semaphore;

            /** @brief Quand il est à false, indique souvent qu'on veut déconnecter le joueur */
            bool valide;

    public :
            /** @brief false si le Joueur n'est pas valide, généralement ceci signifie que le joueur est entré en phase de déconnexion */
            const bool & isValide;

            /** @brief Donne le nombre d'instructions non traitées de ce joueur */
            const int & getCompteur;

            /** @brief Indique si le joueur est connecté ou non
                @return bool : true si le joueur n'est pas connecté, false sinon */
            bool isNotCo(void);

            friend class Traitement;
    };
}
#endif // JOUEUR_H
