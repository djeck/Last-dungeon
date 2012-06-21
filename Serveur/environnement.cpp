#include "environnement.h"

namespace LD
{
    Environnement::~Environnement()
    {

        sem_destroy(&semaphore);
    }

    Environnement::Environnement(int nbJeton) : nbJetonMax(nbJeton)
    {
        sem_init(&semaphore, 0, nbJeton);
    }

    bool Environnement::addJoueur(InfoJoueur * j)
    {
        verrou.lock();
        for(int i=nbJetonMax; i; --i)
            sem_wait(&semaphore);
        List::iterator p = joueurConnecte.begin();
        List::iterator fin = joueurConnecte.end();
        for( ; p !=fin; ++p)
            if( (*p)->id == j->id)
            {  /*
                delete *p;
                joueurConnecte.erase(p); */ //TODO

                for(int i=nbJetonMax; i; --i)
                    sem_post(&semaphore);
                verrou.unlock();
                return true;
            }
        joueurConnecte.push_back(j);
        for(int i=nbJetonMax; i; --i)
            sem_post(&semaphore);
        verrou.unlock();
        return false;
    }

    void Environnement::decoJoueur(InfoJoueur *j)
    {
        verrou.lock();
        for(int i=nbJetonMax; i; --i)
            sem_wait(&semaphore);

        List::iterator p = joueurConnecte.begin();
        List::iterator fin = joueurConnecte.end();
        for( ; p != fin; ++p)
            if( (*p)->id == j->id)
            {
                delete *p;
                joueurConnecte.erase(p);
                for(int i=nbJetonMax; i; --i)
                    sem_post(&semaphore);
                verrou.unlock();
                break;
            }

        for(int i=nbJetonMax; i; --i)
            sem_post(&semaphore);
        verrou.unlock();
    }



    bool Environnement::isConnecte(unsigned int id)
    {
        sem_wait(&semaphore);
        List::iterator p = joueurConnecte.begin();
        List::iterator fin = joueurConnecte.end();
        for( ; p != fin; ++p)
            if((*p)->id == id)
            {
                sem_post(&semaphore);
                return true;
            }

        sem_post(&semaphore);
        return false;
    }



    void Environnement::multicast(sf::Packet & paquet)
    {
        sem_wait(&semaphore);
        List::iterator p = joueurConnecte.begin();
        List::iterator fin = joueurConnecte.end();
        for( ; p != fin; ++p)
            (*p)->socket->send(paquet);
        sem_post(&semaphore);
    }

}
