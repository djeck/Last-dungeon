#include "traitement.h"
#include "../../Communs/enumTraitement.h"
#include "listefonctionserveur.h"
#include "../../Communs/requetebdd.h"
#include "../../Communs/Param.h"
#include "../../Communs/sha512.h"

#include <iostream>

namespace LD
{
    Traitement::Traitement(ListeJoueurs & listeJoueurs, ListeInstruction & listeInstruction, bool & running, bool & coEntrants,
               bool &closeServeurClient, sf::Mutex &verrou, ParamTraitement & param) :
        listeJoueurs(listeJoueurs),             listeInstruction(listeInstruction),
        running(running),                       coEntrants(coEntrants),
        closeServeurClient(closeServeurClient), verrou(verrou),
        param(param)
    {}


    Traitement::~Traitement()
    {

    }

    void Traitement::traiter()
    {
        while(listeInstruction.wait(), running)
        {
            Instruction instruction = listeInstruction.pop_front();
            if( instruction.first->isValide )
            {
                if(! instruction.first->infoJoueur )
                {
                    if( connexion(instruction) )
                    {
                        listeJoueurs.deleteJoueur(*instruction.first);
                        Joueur::deleteJoueur(*instruction.first);
                    }
                }
                else
                {
                    TypeInstruction type;
                    *(instruction.second) >> type;
                    if(type > TRAIT_SERVEUR::FIN)
                    {
                        listeJoueurs.deleteJoueur(*instruction.first);
                        Joueur::deleteJoueur(*instruction.first);
                    }
                    else if( LISTE_FCT[type](instruction, param) )
                    {
                        listeJoueurs.deleteJoueur(*instruction.first);
                        Joueur::deleteJoueur(*instruction.first);
                    }
                }
            }
            else
                Joueur::deleteJoueur(*instruction.first);
            --*instruction.first;
           delete instruction.second;
        }

    }



    bool Traitement::connexion(Instruction & instruction)
    {
        sf::TcpSocket & socket = instruction.first->socket;
        std::string login, password;
        *instruction.second >> login;
        InfoJoueur * infoJoueur;
        std::cout << "Traitement : " << login << std::endl;
        if(! (infoJoueur = RequeteBDD::getJoueur(login) ) )
        {
            std::cout << infoJoueur << std::endl;
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::FAUXID;
            socket.send(paquet);
            return true;
        }
        std::cout << "login valide" << std::endl;
        if(infoJoueur->bloque > (unsigned long long)time(NULL))
        {
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::BLOQUE << (sf::Uint32)(infoJoueur->bloque - time(NULL)) << infoJoueur->raisonBan;
            socket.send(paquet);
            return true;
        }


        if(infoJoueur->banni)
        {
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::BANNI << infoJoueur->raisonBan;
            socket.send(paquet);
            return true;
        }


        unsigned long long hash[8];
        sf::Uint32 * ptr = (sf::Uint32 *)hash;
        for(int i =0; i != 16; ++i, ++ptr)
            *instruction.second >> *ptr;

        if(Sha512(hash).getHexadecimal(password) != infoJoueur->hash)
        {
            ++infoJoueur->echec;
            sf::Packet paquet;
            time_t temps = 0;
            if( (infoJoueur->echec% CO_JOUEURS::NB_MAX_ECHEC) == 0)
            {
                time(&temps);
                temps += CO_JOUEURS::ATTENTE;
                paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::BLOQUE << (sf::Uint32)CO_JOUEURS::ATTENTE << CO_JOUEURS::MSG_BLOQUE;
            }
            else
                paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::FAUXID;
            RequeteBDD::setBloque(infoJoueur->id, temps, CO_JOUEURS::MSG_BLOQUE, infoJoueur->echec);
            socket.send(paquet);
            return true;
        }


          if( infoJoueur->droits & (1<<DROITS::ACCES) )
          {
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::ADMIN_BAD_PORT;
            socket.send(paquet);
            return true;
          }

        if( listeJoueurs.deleteJoueur(*instruction.first) )
        {
            sf::Packet reponse;
            reponse << (TypeInstruction)TRAIT_CLIENT::CONNEXION::DEJACO;
            socket.send(reponse);
            return true;
        }


          //Connexion réussie
         RequeteBDD::setBloque(infoJoueur->id, 0, "", 0);
         instruction.first->infoJoueur = infoJoueur;
         sf::Packet reponse;
         reponse << (TypeInstruction)TRAIT_CLIENT::CONNEXION::REUSSIE << (sf::Uint32)infoJoueur->echec;
         socket.send(reponse);
         return false;
    }
}
