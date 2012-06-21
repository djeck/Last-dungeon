#include "serveur.h"
#include "../../Console/Console/logger.h"
#include <iostream>

/** @mainpage La partie serveur a pour but d'encapsuler au maximum l'architecture spécifique du serveur et aux yeux du programmeur.
  Le programmeur aura juste à définir les constantes pour un traitement et de rajouter son traitement dans le switch approprié.
  Il pourra alors envoyer des données grâce à des fonctions d'envois de paquets à une liste de clients ou à un client spécifique.

  Pour plus de détails, lisez le README présent à la racine du dépôt github : https://github.com/Neckara/Projet
  */

int main(void)
{
    try
    {
        LD::Serveur serveur;
        serveur.start();
    }
    catch(const std::string & e)
    {
        std::cout << e << std::endl;
        LD::Logger::closeLog();
    }

    return 0;
}

/* ------------INSERTION JOUEURS -----------
#include "../../Console/Console/bdd.h"
#include "sha512.h"

int main(void)
{
    LD::Sha512 sha("mdp");
    std::string password;
    sha.getHexadecimal(password);
    try
    {
        std::string requete = "INSERT INTO Joueurs VALUES('', 'denis', x'"+ password +"')";
        delete & LD::BDD::requeteBDD(LD::BDD_PARAM::JOUEURS, requete);
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }
    return 0;
}
*/
