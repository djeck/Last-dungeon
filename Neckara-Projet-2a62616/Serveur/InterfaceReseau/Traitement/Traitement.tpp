#ifndef TRAITEMENT_TPP
#define TRAITEMENT_TPP

#include "Traitement.h"

namespace LD
{
    template<typename Logs, typename Mode>
    Traitement<Logs, Mode>::Traitement(ListeJoueurs & listeJoueurs, ListeInstruction * listeInstruction,
        bool & running, bool & coEntrants,
        bool &closeServeurClient, ParamTraitement & param) :
        listeJoueurs(listeJoueurs),             listeInstruction(listeInstruction),
        running(running),                       coEntrants(coEntrants),
        closeServeurClient(closeServeurClient),
        param(param)
    {}

    template<typename Logs, typename Mode>
    Traitement<Logs, Mode>::~Traitement()
    {

    }

    template<typename Logs, typename Mode>
    void Traitement<Logs, Mode>::traiter(void)
    {
        while(listeInstruction->wait(), running)
        {
            Instruction instruction = listeInstruction->pop_front();
            traiterInstruction(instruction);
        }

    }

    template<typename Logs, typename Mode>
    void Traitement<Logs, Mode>::traiterInstruction(Instruction & instruction)
    {
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



    template<typename Logs, typename Mode>
    bool Traitement<Logs, Mode>::connexion(Instruction & instruction)
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
            if( (infoJoueur->echec% mode.getMaxEchec() ) == 0)
            {
                time(&temps);
                temps += mode.getAttente();
                paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::BLOQUE << (sf::Uint32)mode.getAttente() << mode.getMessage();
            }
            else
                paquet << (TypeInstruction)TRAIT_CLIENT::CONNEXION::FAUXID;
            RequeteBDD::setBloque(infoJoueur->id, temps, mode.getMessage(), infoJoueur->echec);
            socket.send(paquet);
            return true;
        }

        if( mode.isBonPort(infoJoueur->droits, socket) )
        {
            return true;
        }

        Joueur * j = listeJoueurs.deleteJoueur(infoJoueur->id);
        if(j)
        {
            sf::Packet reponse;
            reponse << (TypeInstruction)TRAIT_CLIENT::CONNEXION::DEJACO;
            sf::Packet reponse2 = reponse;
            j->sendMessage(reponse2);
            Joueur::deleteJoueur(*j);

            socket.send(reponse);
            return true;
        }


          //Connexion réussie
         RequeteBDD::setBloque(infoJoueur->id, 0, "", 0);
         instruction.first->infoJoueur = infoJoueur;

         listeJoueurs.addJoueur(*instruction.first);

         sf::Packet reponse;
         reponse << (TypeInstruction)TRAIT_CLIENT::CONNEXION::REUSSIE << (sf::Uint32)infoJoueur->echec;
         socket.send(reponse);
         return false;
    }

}
#endif // TRAITEMENT_TPP
