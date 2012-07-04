#include "listejoueurs.h"

#include <iostream>

namespace LD
{
    ListeJoueurs::ListeJoueurs(int nbThread) : nbMaxSem(nbThread)
    {
        sem_init(&semaphore, 0, nbThread);
    }


    ListeJoueurs::~ListeJoueurs()
    {
        sem_destroy(&semaphore);
    }


    void ListeJoueurs::addJoueur(Joueur & j)
    {
        Ecriture.lock();
        for(int i=0; i != nbMaxSem; ++i)
            sem_wait(&semaphore);

        listeJoueur.push_back(&j);

        for(int i=0; i != nbMaxSem; ++i)
            sem_post(&semaphore);
        Ecriture.unlock();
    }

    Joueur * ListeJoueurs::deleteJoueur(Joueur & j)
    {
        Ecriture.lock();
        for(int i=0; i != nbMaxSem; ++i)
            sem_wait(&semaphore);

        std::list<Joueur *>::const_iterator const fin = listeJoueur.end();
        for( std::list<Joueur *>::iterator p = listeJoueur.begin() ; p != fin; ++p )
            if( j == **p )
            {
                Joueur * retour = *p;
                listeJoueur.remove(*p);
                for(int i=0; i != nbMaxSem; ++i)
                    sem_post(&semaphore);
                Ecriture.unlock();
                return retour;
            }

        for(int i=0; i != nbMaxSem; ++i)
            sem_post(&semaphore);
        Ecriture.unlock();
        return NULL;
    }

    void ListeJoueurs::broadcast(sf::Packet & paquet)
    {
        sem_wait(&semaphore);

        std::list<Joueur *>::const_iterator const fin = listeJoueur.end();
        for( std::list<Joueur *>::iterator p = listeJoueur.begin() ; p != fin; ++p )
            (*p)->sendMessage(paquet);

        sem_post(&semaphore);
    }


    Joueur * ListeJoueurs::isPresent(Joueur & j)
    {
        sem_wait(&semaphore);


        std::list<Joueur *>::const_iterator const fin = listeJoueur.end();
        for( std::list<Joueur *>::iterator p = listeJoueur.begin() ; p != fin; ++p )
            if( j == (**p) )
            {
                sem_post(&semaphore);
                return *p;
            }

        sem_post(&semaphore);
        return NULL;
    }
}
