#ifndef LISTEINSTRUCTION_H
#define LISTEINSTRUCTION_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <list>

#include "joueur.h"
#include "semaphore.h"

namespace LD
{

    /** @brief Instruction */
    typedef std::pair<Joueur *, sf::Packet *> Instruction;

    /** @brief Classe contenant la liste de toutes les instructions à effectuer */
    class ListeInstruction
    {
    public:
        ListeInstruction();
        ~ListeInstruction();


        /** @brief attent une instruction */
        void wait(void);


        /** @brief Permet d'ajouter une instruction à la liste
            @param  sf::Packet & : données envoyées (/!\ doit être alloué dynamiquement)
            @param Joueur & : expéditeur
            @return int : nombre de traitements contenu dans la liste, permet au thread listenner de bloquer les connexions entrantes en cas
            de surchage */
        int push_back(sf::Packet &, Joueur &);

        /** @brief Retourne l'instruction en tête de la liste et la supprime de cette liste
            @return Instruction à traiter */
        Instruction pop_front(void);

        /** @brief Permet de libérer nbThread
            @param int nbThread : nombre de thread à libérer */
        void liberer(int nbThread);
        private :
            /** @brief nombre d'instructions contenues dans la liste */
            sem_t compteur;

            /** @brief Mutex permettant l'accès unique à la liste pendant un instant T */
            sf::Mutex verrou;

            /** @brief Liste d'instruction */
            std::list<Instruction> listeInstruction;
    };


}
#endif // LISTEINSTRUCTION_H
