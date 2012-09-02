#ifndef BDD_H
#define BDD_H

//TODO regarder la licence de mysql

#include <mysql/mysql.h>
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <sstream>


#include "Param.h"
#include "resultatrequete.h"
/*
Installer mysql :
aptitude install libmysqlclient15-dev
aptitude install mysql-server

Compiler :

g++ bdd.cpp -o exe -lmysqlclient
*/

namespace LD
{

    struct Resultat;

    /** @brief classe servant �  encapsuler l'accès �  une Base de Données */
    class BDD
    {
        private :
                /** @brief liste des différentes Base de Données */
                static std::vector<BDD *> listeBDD;

                /** @brief mutex pour qu'on ne puisse avoir qu'un accès par table �  la fois */
                static sf::Mutex verrou[BDD_PARAM::MAX];
        public :
                /** @brief permet d'envoyer une requête �  la BDD et l'ouvre si elle ne l'est pas.
                  /!\ Peut renvoyer une exception (std::string)
                    @param int idBDD : identifiant de la table
                    @param const string & requete : requête �  envoyer �  la Base de Donnée.
                    @return Resultat & : instance de la classe Resultat, contient le résultat retournée par la requête */
                static Resultat & requeteBDD(BDD_PARAM::IdBDD idBDD, const std::string & requete);

                /** @brief Permet de fermer la connexion �  une table
                    @param BDD_PARAM::IdBDD idBDD : identifiant de la table �  fermer */
                static void closeBDD(BDD_PARAM::IdBDD idBDD);
                /** @brief Permet de fermer tous les connexions aux tables */
                static void closeAllBDD();

                /** @brief Protège la BDD contre les injections SQL, chaque donnée doit être vérifiée avant d'être intégrée �  une requête SQL
                  @param std::string & chaîne : chaîne �  traiter
                   @return  std::string & : référence vers la chaine */
                static std::string & antiInjection(std::string & chaine);
    private :
            /** @brief Variable nécessaire pour l'utilisation d'une base de données mysql, lien d'une connexion �  une base de donnée */
                    MYSQL conn;
                    /** @brief Permet d'ouvrir une table
                        @param const char * adresse : adresse de la table
                        @param const char * login : login utilisé pour se connecter �  la table
                        @param const char * password : mot de passe utilisé pour se connecter �  la table
                        @param const char * table : table �  laquelle se connecter */
                    BDD(const char * adresse, const char * login, const char * password, const char * table);


                    /** @brief permet de fermer la table */
                    ~BDD();

                    /** @brief permet d'envoyer une requête
                        @param const std::string & requete : requête �  envoyer
                        @return MYSQL_RES * : résultat de la requête, NULL si erreur */
                    MYSQL_RES * requete(const std::string & requete);
    };

    /** @brief contient le résultat de la requête BDD.
        Lorsque requeteBDD renvois un Resultat, il est conseillé de surcharger l'opérateur d'affectation de la classe courante afin de traiter directement le résultat */

    struct Resultat
    {
      public :

            /** @brief Nombre de lignes */
            int nbLigne;
            /** @brief Nombre de colonne */
            int nbColonne;
            /** @brief résultat de la requête */
            LigneResultatRequete * resultat;

            /** @brief On peut accéder aux différentes lignes du résultat de la requête grâce �  l'opérateur [].
                   @param int i : numéro de la ligne (commence �  0)
                   @return const LigneResultatRequete & : ligne demandée */
            const LigneResultatRequete & operator[](int i) const;

            /** @brief construit un résultat
                @param MYSQL_RES * resultat : réponse de MySQL */
            Resultat(MYSQL_RES * resultat);

            /** @brief détruit le résultat */
            ~Resultat();
    };

}
#endif // BDD_H
