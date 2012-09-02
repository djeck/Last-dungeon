#include <iostream>
#include <limits>
#include <stdlib.h>
#include <fstream>

#include "menubash.h"
#include "versionfile.h"
#include "UnixWindows.h"


namespace LD
{
/** @brief Noms des paramètres */
    enum{RepTravail, RepProjet, CheminBDD, LoginBDD, Max};

    const int maxParam = Max + 1;
    MenuBash::MenuBash()
    {
    }

    void MenuBash::start()
    {
        load();
        clear();
        affichage();
        std::cin.clear();
        char choix;
        std::cin >> choix;
        while(choix != 'q')
        {
            clear();
            // il aurait été plus générique de faire un tableau de classe encapsulant des méthodes ou des fonctions.
            switch(choix)
            {
                case '1':
                   makeLisible();
                break;
                case 'q' :
                break;
                case 'p' :
                    param();
                break;
                default :
                    choixInvalide(choix);
                break;
            }
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> choix;
        }

        std::cout << "credits" << std::endl;
    }

    void MenuBash::affichage(void)
    {
        std::cout << "------- Menu Principal ------" << std::endl;
        std::cout << "Etape 1 :\n"
                  << "1\tGenerer fichier de version lisible" << std::endl;
        //Générer version finale
        //Transformer version lisible en version finale <- Demain ->
        //Envoyer la version finale
        //Etape 2 :
        //Précalculer les instructions pour toutes les versions X.0.
        //Précalculer les instructions pour toutes les versions X.0 et
        //Précalculer les instructions pour toutes les versions. <- Après-demain ->
        //Etape 3 :
        //Envoyer les données
        //Etape 4 :
        //Sauvegarder la version
        //Etape 5 :
        //Supprimer les fichiers inutiles <Après-après-demain
        std::cout << "Autre :\n"
                     << "p\tParametres\n"
                     << "q\tQuitter" << std::endl;
    }

    void MenuBash::choixInvalide(char choix)
    {
        affichage();
        std::cout << "\n'" << choix << "' n'est pas un choix valide" << std::endl;
        std::cout << "Entrez un nouveau choix : ";
    }

    void MenuBash::makeLisible(void)
    {
        std::cout << "Demarrage de la creation d'un fichier de mises a jours lisible a partir du dossier " << var[RepProjet] << std::endl;
        VersionFile version;
        std::string repMajLisible = var[RepTravail];
        symboleDossier(repMajLisible);
        repMajLisible += "MajLisibleFiles";
        std::string reponse = version.Create(repMajLisible.c_str() , "MajLisibleFile", var[RepProjet].c_str(), NULL, true);
        clear();
        affichage();
        if(reponse != "")
            std::cout << "\n" << reponse << std::endl;
        else
            std::cout << "\nLe fichier de mises a jours lisible (MajLisibleFile) a ete cree, vous pouvez desormais l'editer a la main." << std::endl;
    }

    void MenuBash::param(void)
    {
        bool continu = true;
        char choix;
        std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
        while(continu)
        {
            std::cout << "------- Parametres ------" << std::endl;
            std::cout << "Num.\tNom\t\tValeur" << std::endl;
            std::cout << (RepTravail+1) << "\tRep. de Travail\t" << var[RepTravail] << "\n"
                      << (RepProjet+1) << "\tRep. du Projet\t" << var[RepProjet] << "\n"
                      << (CheminBDD + 1) << "\tChemin BDD\t" << var[CheminBDD] << "\n"
                      << (LoginBDD + 1) << "\tLogin BDD\t" << var[LoginBDD] << "\n"
                      << "" << std::endl;
            std::cout << "Tapez le numero pour modifier la variable, entrez une autre valeur pour quitter" << std::endl;

            std::cin >> choix;
            if(choix > '0' && choix < ('0' + maxParam ) )
            {
                std::cout << "Entrez la nouvelle valeur : ";
                std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
                std::string tmp;
                std::getline(std::cin, tmp);
                var[choix - '1'] = tmp;
            }
            else
                continu = false;
            clear();
        }
        affichage();
        save();
    }

    void MenuBash::clear(void)
    {
        //Unix : system("clear");
        system("cls");//Windows
    }

    void MenuBash::save(void)
    {
        std::ofstream fichier("param");
        if(fichier)
        {
            for(int i = 0; i < maxParam; ++i)
                fichier << var[i] << '\n';
            fichier.close();
        }
        else
        {
            std::cerr << "Erreur lors de la sauvegarde des parametres" << std::endl;
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n');
            char wait;
            std::cout << "Entrez une valeur quelconque pour continuer" << std::endl;
            std::cin >> wait;
        }
    }

    void MenuBash::load()
    {
        std::ifstream fichier("param");
        if(fichier)
        {
            std::cout << "Chargement des parametres..." << std::endl;
            for(int i = 0; i < maxParam; ++i)
                getline(fichier, var[i]);
        }
        else
        {
            std::cerr << "Aucun fichier de parametre trouve, utilisation des valeurs par defaut" << std::endl;
            var[RepTravail] = ".";
            var[RepProjet] = ".";
            var[CheminBDD] = "localhost";
            var[LoginBDD] = "root";
        }
    }
}
