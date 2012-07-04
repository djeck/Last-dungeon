#include "traitement.h"
#include "../../Communs/enumTraitement.h"
#include "listefonctionserveur.h"
#include "../../Communs/requetebdd.h"
#include "../../Communs/Param.h"

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
                TypeInstruction type;
                *(instruction.second) >> type;
                if(type > TRAIT_SERVEUR::FIN)
                {
                    listeJoueurs.deleteJoueur(*instruction.first);
                    Joueur::deleteJoueur(*instruction.first);
                }
                else if(instruction.first->isNotCo() )
                {
                    if( connexion(instruction) )
                    {
                        listeJoueurs.deleteJoueur(*instruction.first);
                        Joueur::deleteJoueur(*instruction.first);
                    }
                }
                else if( LISTE_FCT[type](instruction, param) )
                {
                    listeJoueurs.deleteJoueur(*instruction.first);
                    Joueur::deleteJoueur(*instruction.first);
                }
            }
            else
                Joueur::deleteJoueur(*instruction.first);
            --*instruction.first;
        }

    }



    bool Traitement::connexion(Instruction & instruction)
    {
        sf::TcpSocket & socket = instruction.first->socket;
        std::string login, password;
        *instruction.second >> login;
        InfoJoueur * infoJoueur;

        if(infoJoueur = RequeteBDD::getJoueur(login, joueur) )
        {
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::FAUXID;
            socket->send(paquet);
            return true;
        }

        if(infoJoueur->bloque > (unsigned long long)time(NULL))
        {
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::BLOQUE << (sf::Uint32)(joueur.bloque - time(NULL)) << joueur.raisonBan;
            socket->send(paquet);
            return false;
        }

        if(infoJoueur->banni)
        {
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::BANNI << joueur.raisonBan;
            socket->send(paquet);
            return false;
        }


        unsigned long long hash[8];
        sf::Uint32 * ptr = (sf::Uint32 *)hash;
        for(int i =0; i != 16; ++i, ++ptr)
            paquet >> *ptr;

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
                paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION_C::FAUXID;
            RequeteBDD::setBloque(infoJoueur->id, temps, CO_JOUEURS::MSG_BLOQUE, infoJoueur->echec);
            socket->send(paquet);
            return false;
        }


          if( infoJoueur->droits & (1<<DROITS::ACCES) )
          {
            sf::Packet paquet;
            paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::ADMIN_BAD_PORT;
            socket->send(paquet);
            return false;
          }

        if( deleteJoueur(*instruction.first) )
        {
            sf::Packet reponse;
            reponse << (TypeInstruction)TRAIT_CLIENT::CONNEXION::DEJACO;
            socket->send(reponse);
            return false;
        }


          //Connexion réussie
         RequeteBDD::setBloque(infoJoueur->id, 0, "", 0);
         instruction->first->infoJoueur = infoJoueur;
         sf::Packet reponse;
         reponse << (TypeInstruction)TRAIT_CLIENT::CONNEXION::REUSSIE << (sf::Uint32)joueur->echec;
         socket->send(reponse);
         return false;
    }
}
