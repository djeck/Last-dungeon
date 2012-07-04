#include "joueur.h"
#include "listener.h"

#include <iostream>

namespace LD
{
    Joueur::Joueur(Listener & listener, sf::TcpSocket & socket, int nbThread) :
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
        std::cout << "fin socket" << std::endl;
        //TODO enregistrer les données
        sem_destroy(&semaphore);
    }

    void Joueur::deleteJoueur(Joueur & j)
    {
        j.ecriture.lock();
        if(j.valide)
        {
            j.valide = false;
        }
        if(j.compteur == 1) //l'instruction en cours est comptée dans le compteur
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
        if(! (other.infoJoueur && infoJoueur) )
            return false;
        return true; //TODO *infoJoueur == *other.infoJoueur;
    }

    bool Joueur::isNotCo(void)
    {
        return infoJoueur;
    }
}
