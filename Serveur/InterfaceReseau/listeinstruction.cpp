#include "listeinstruction.h"

#include <iostream>

namespace LD
{

    ListeInstruction::ListeInstruction()
    {
        sem_init(&compteur, 0, 0);
    }


    ListeInstruction::~ListeInstruction()
    {

    }


    int ListeInstruction::push_pack(sf::Packet & paquet, Joueur & joueur)
    {
        ++joueur;
        verrou.lock();
        listeInstruction.push_back(Instruction(&joueur, &paquet) );
        verrou.unlock();
        sem_post(&compteur);
        int retour;
        sem_getvalue(&compteur, &retour);
        return retour;
    }

    void ListeInstruction::wait(void)
    {
        sem_wait(&compteur);
    }

    Instruction ListeInstruction::pop_front(void)
    {
        verrou.lock();
        Instruction & tmp = listeInstruction.front();
        listeInstruction.pop_front();
        verrou.unlock();
        --*tmp.first;
        return tmp;
    }

    void ListeInstruction::liberer(int nbThread)
    {
        while(nbThread)
        {
            sem_post(&compteur);
            --nbThread;
        }

    }
}
