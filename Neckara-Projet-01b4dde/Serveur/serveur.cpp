#include <list>

#include "serveur.h"
#include "administrateur.h"
#include "../Communs/logger.h"
#include "InterfaceReseau/Traitement/traitementclient.h"
#include "InterfaceReseau/Listener/listenerclient.h"


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
        ListenerClient listener(port, running, nbThread, 15, closeServeurClient, coEntrant, listeInstruction);//(port, running, listeInstruction, coEntrant, closeServeurClient, verrou, nbThread);
        TraitementClient traitement(listeJoueurs, &listeInstruction, running, coEntrant, closeServeurClient, param);

        sf::Thread * thread[nbThread];

        //--------- Création des threads consommateurs ------------

        for(int i=0; i != nbThread; ++i)
        {
            thread[i] = new sf::Thread( (void(VirtualTraitement::*)() )&VirtualTraitement::traiter, (VirtualTraitement *)&traitement);
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
