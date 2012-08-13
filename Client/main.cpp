/**
@mainpage Client partiel du jeux développé pour les tests du serveur.
On utilise un interface console, après avoir lancé le serveur, il suffit de lancer le client, d'entrer le pseudo puis le mot de passe pour se connecter

Crtl+C pour quitter sous Linux

Pour plus de détails, référez-vous au README se trouvant à la racine du dépôt github : https://github.com/Neckara/Projet
*/

// Penser à inclure les commentaires de premières pages

#include "../Communs/logger.h"
#include <SFML/Network.hpp>
#include "../Communs/Param.h"
#include "../Communs/enumTraitement.h"


/** @brief Traite le paquet reçu côté client */
void traitement(sf::Packet & paquet);

/** @brief Traite le paquet reçu côté client si celui-ci traite de la connexion */
void traitement_connexion(sf::Packet & paquet);

/** @brief Stocke les informations joueurs utiles */
class Joueur;

/** @brief Paramètres nécessaire au traitement des instructions reçues du serveur */
struct Param
{
    Param(sf::TcpSocket & socket) : socket(socket){}
    sf::TcpSocket &socket;
};

/** @brief Fonction de traitement client */
typedef bool (*FctTraitement)(sf::Packet &, Param &);

bool deco(sf::Packet &, Param &);

/** @brief Le client reçoit un message selon lequel son ip aurait été bannie
@param sf::Packet & paquet: paquet reçu
@param Param & : paramètres
@bool : retourne true*/
bool ipBan(sf::Packet & paquet, Param &);

/** @brief Le client a entré un identifiant ou un mot de passe invalide
@param sf::Packet & paquet: paquet reçu
@param Param & : paramètres
@bool : retourne true*/
bool fauxId(sf::Packet & paquet, Param &);

/** @brief Le client reçoit un message selon lequel son compte aurait été bloque
@param sf::Packet & paquet: paquet reçu
@param Param & : paramètres
@bool : retourne true*/
bool bloque(sf::Packet & paquet, Param &);

/** @brief Le client reçoit un message selon lequel son compte aurait été banni
@param sf::Packet & paquet: paquet reçu
@param Param & : paramètres
@bool : retourne true*/
bool banni(sf::Packet & paquet, Param &);

/** @brief Le port utilisé n'est pas le bon (admin)
@param sf::Packet & paquet: paquet reçu
@param Param & : paramètres
@bool : retourne true*/
bool badPort(sf::Packet & paquet, Param &);

/** @brief Le client est déjà connecté
@param sf::Packet & paquet: paquet reçu
@param Param & : paramètres
@bool : retourne true*/
bool dejaCo(sf::Packet & paquet, Param &);

/** @brief La connexion a réussie
@param sf::Packet & paquet: paquet reçu
@param Param & : paramètres
@bool : retourne true*/
bool coReussie(sf::Packet & paquet, Param &);

/** @brief liste des fonctions de traitement client */
extern const FctTraitement LISTE_FCT[] = {&deco, NULL, &ipBan, &fauxId, &bloque, &banni, &badPort, &dejaCo, &coReussie};

#include "../../Serveur/Serveur/sha512.h"
int main(void)
{
    // Send a message to the connected host
    sf::Packet packet;
    std::cout << "Administrateur veuillez vous identifier" << std::endl;
    std::string login, password;
    std::cin >> login;
    std::cin.ignore();
    std::cin >> password;
    std::cin.ignore();
    packet << login;

     sf::TcpSocket socket;
     sf::SocketSelector selector;

     socket.connect("127.0.0.1", LD::ADMINISTRATEUR_PARAM::PORT);
     selector.add(socket);
     Param param(socket);

     sf::Uint32 * hash = (sf::Uint32 *)LD::Sha512(password).getHash();
     for(int i = 0; i != 16; ++i)
     {
         packet << hash[i];
     }
     socket.send(packet);

     std::cout << "paquet envoyé" << std::endl;

     bool running = true;

     while(running)
     {
         selector.wait();
         std::cout << "o" << std::endl;
         if(selector.isReady(socket))
         {
             sf::Packet packet;
             if(socket.receive(packet) == sf::Socket::Done)
             {
                 std::cout << "paquet reçu" << std::endl;
                 LD::TypeInstruction type;
                 packet >> type;
                 if(type > LD::TRAIT_CLIENT::FIN)
                     running = false;
                 if(LISTE_FCT[type](packet, param) )
                     running = false;
             }
             else
                 running = false;
         }
         else running = false;
    }
    std::cout << "Fermeture du client" << std::endl;

    socket.disconnect();
    selector.remove(socket);
    return 0;
}


bool deco(sf::Packet &, Param &)
{
    return true;
}


bool ipBan(sf::Packet & paquet, Param &)
{
    std::cout << "Votre ip a été bannie pour la raison suivante :" << std::endl;
    std::string raison;
    paquet >> raison;
    std::cout << raison << std::endl;
    return true;
}

bool fauxId(sf::Packet &, Param &)
{
    std::cout << "Login ou mot de passe invalide" << std::endl;
    return true;
}

bool bloque(sf::Packet & paquet, Param &)
{
    sf::Uint32 temps;
    std::string raison;
    paquet >> temps;
    paquet >> raison;
    std::cout << "Ce compte a été bloqué pour la raison suivante : " << std::endl;
    std::cout << raison << std::endl;
    std::cout << "Veuillez patienter " << temps/(3600*24) << " jours " << temps/3600%24<< " heures " << temps/60%60 << " minutes et " <<  temps%60 << " secondes" << std::endl;
    return true;
}

bool banni(sf::Packet & paquet, Param &)
{
    std::cout << "Votre compte a été banni pour la raison suivante :" << std::endl;
    std::string raison;
    paquet >> raison;
    std::cout << raison << std::endl;

    return true;
}

bool badPort(sf::Packet &, Param &)
{
    std::cout << "Cher administrateur, vous n'utilisez pas le bon port de connexion !" << std::endl;
    return true;
}

bool dejaCo(sf::Packet &, Param &)
{
    std::cout << "Vous êtes déjà connecté, vous serez donc déconnecté" << std::endl;
    return true;
}


bool coReussie(sf::Packet &p, Param &)
{
    sf::Uint32 essais;
    p >> essais;
    std::cout << "Connexion réussie!" << std::endl;
    std::cout << "Pendant votre absence, vous avez eu " << essais << " nombres de tentatives à votre compte infructueuse" << std::endl;
    return false;
}

