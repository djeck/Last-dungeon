#include "serveur.h"
#include "administrateur.h"
#include "../Communs/logger.h"
#include "InterfaceReseau/traitement.h"
#include <list>


namespace LD
{
    Serveur::Serveur(unsigned int port, int nbThread) :
            nbThread(nbThread), port(port), running(true),
            coEntrant(false), closeServeurClient(false),
            listeJoueurs(nbThread+1),
            param(running)
    {
    }

    void Serveur::startAdmin(void)
    {
        //Administrateur admin;
        //TODO gentillesse
        start();
    }

    void Serveur::start()
    {
        //--------- Création des paramètres -----------------------
        Listener listener(port, running, listeInstruction, coEntrant, closeServeurClient, verrou, nbThread);

        Traitement traitement(listeJoueurs, listeInstruction, running, coEntrant, closeServeurClient, verrou, param);

        sf::Thread * thread[nbThread];

        //--------- Création des threads consommateurs ------------

        for(int i=0; i != nbThread; ++i)
        {
            thread[i] = new sf::Thread(&Traitement::traiter, &traitement);
            thread[i]->launch();
        }

        //--------- lancement de l'écoute -------------------------

        listener.start();

        //--------- attente de la fin des threads consommateurs ---
        listeInstruction.liberer(nbThread);
        for(int i=0; i != nbThread; ++i)
            thread[i]->wait();

        //--------- destructions diverses -------------------------
    }
}
