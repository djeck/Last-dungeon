#ifndef LISTEJOUEURS_H
#define LISTEJOUEURS_H


#include "joueur.h"

#include <SFML/Network.hpp>
#include <list>
#include <semaphore.h>


namespace LD
{
    /** @brief Classe représentant une liste de joueurs
    /!\ N'est pas adapté aux listes temporaires de joueurs comme les groupes
    Remarque : Il faudrait remplacer les std::list par des tables de hachage pour plus de performances lors de la recherche, idem dans listener.h */
    class ListeJoueurs
    {
    public:
        /** @brief Construit une liste de joueur
            @param int nbThread : nombre de threads pouvant lire la liste de joueur simultanément */
        ListeJoueurs(int nbThread);
        virtual ~ListeJoueurs();

        /** @brief Ajoute un joueur
            @param  Joueur & j : joueur à ajouter */
        void addJoueur(Joueur & j);

        /** @brief Enlève un joueur de la liste
            @param Joueur & j : joueur à enlever
            @return Joueur * : pointeur sur le joueur trouvé ou NULL sinon */
        Joueur * deleteJoueur(Joueur & j);

        /** @brief Envois d'un message à tous les joueurs de la liste
            @param  sf::Packet & p : paquet à envoyer */
        void broadcast(sf::Packet & p);

        /** @brief retourne true si le joueur est présent dans la liste
            @param Joueur & j : joueur à rechercher
            @return Joueur * : pointeur sur le joueur trouvé ou NULL sinon */
         Joueur * isPresent(Joueur & j);
    private :
            /** @brief Liste des joueurs appartenant à la liste */
            std::list<Joueur *> listeJoueur;


            /** @brief Permet de garantir l'accès unique des opérations d'écritures sur la liste */
            sf::Mutex Ecriture;

            /** @brief Permet d'empêcher des opérations d'écritures concurentes à des opérations de lecture sur la liste */
            sem_t semaphore;

            /** @brief Valeur maximale du sémaphore */
             const int nbMaxSem;
    };
}
#endif // LISTEJOUEURS_H
