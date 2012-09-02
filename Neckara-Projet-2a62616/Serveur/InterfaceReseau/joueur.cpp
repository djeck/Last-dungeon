#include <iostream>

#include "joueur.h"
#include "Listener/virtuallistener.h"

namespace LD
{
    Joueur::Joueur(VirtualListener & listener, sf::TcpSocket & socket, int nbThread) :
            listener(listener), socket(socket),
            infoJoueur(NULL), compteur(0),
            valide(true), isValide(valide),
            getCompteur(compteur)
    {
        sem_init(&semaphore, 0, nbThread);
    }

    Joueur::~Joueur()
    {
        delete &socket;

        //TODO saveData
        sem_destroy(&semaphore);
    }

    void Joueur::deleteJoueur(Joueur & j)
    {
        j.ecriture.lock();
        if(j.valide)
        {
            j.listener.delSocket(j);
            j.socket.disconnect();
            j.valide = false;
        }
        if(j.compteur <= 1) //l'instruction en cours est comptée dans le compteur
            delete &j;
        j.ecriture.unlock();
    }

    bool Joueur::sendMessage(sf::Packet & paquet)
    {
        if(! valide)
            return false;
        return socket.send(paquet) == sf::Socket::Done;
    }

    void Joueur::operator++(void)
    {
        ++compteur;
    }

    void Joueur::operator--(void)
    {
        --compteur;
    }

    bool Joueur::operator==(const Joueur & other)
    {
        if(! (other.valide && valide) )
            return false;
        bool retour = false;
        sem_wait(&semaphore);
        if(other.infoJoueur && infoJoueur)
        {
            retour = (infoJoueur->id == other.infoJoueur->id);
        }
        sem_post(&semaphore);
        return retour;
    }

    bool Joueur::operator==(unsigned int other)
    {
        if(! valide )
            return false;
        bool retour = false;
        sem_wait(&semaphore);
        if(infoJoueur)
        {
            retour = (infoJoueur->id == other);
        }
        sem_post(&semaphore);
        return retour;
    }

    bool Joueur::isNotCo(void)
    {
        return infoJoueur;
    }
}
