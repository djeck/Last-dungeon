#ifndef VERSIONFILE_H
#define VERSIONFILE_H

#include <string>
#include <map>


#include "arborescance.h"

namespace LD
{
    /** @brief Contient deux pointeurs vers des fichiers ayant le même hash */
    struct PairHash //Vous noterez ce subtile jeux de mots (Un indice : Lyon).
    {
        PairHash() : old(NULL), nouv(NULL){}
        /** @brief pointeur vers l'ancien fichier */
        Arborescance::Maillon * old;
        /** @brief pointeur vers le nouveau fichier */
        Arborescance::Maillon * nouv;
    };

/** @brief Génère un fichier de version */
    class VersionFile
    {
    public:
        VersionFile();
        /** @brief Génère un fichier de version
          @param const char * path : dossier où mettre le fichier ainsi créé
          @param const char * destination : fichier à obtenir, s'il existe déjà, renomme le fichier en saveX
          @param const char *repProjet : répertoire où se trouve le logiciel à mettre à jour
          @param Arborescence * arbre : arborescence de la dernière version.
          @param bool lisible : indique si on souhaite ou non obtenir un fichier de version lisible
          @return std::string : retourne "" si tout c'est bien passé, et un message si erreur */
        std::string Create(const char * path, const char * destination,const char *repProjet, Arborescance * arbre, bool lisible = false);
        /** @brief Génère un fichier de version à partir d'un fichier de version lisible
            @param const char * path : dossier où mettre le fichier ainsi créé
            @param const char * destination : fichier à obtenir, s'il existe déjà, renomme le fichier en saveX
            @param const char * source : fichier de version lisible à traduire en fichier de version
            @return std::string : retourne "" si tout c'est bien passé, et un message si erreur */
        std::string Create(const char * path, const char * destination, const char * source);
    private :
        /** @brief Indique si le fichier existe. Si c'est le cas, le renomme en saveX
          @param const char * path : dossier où mettre le fichier ainsi créé
          @param const char * file : fichier à rechercher
          @return bool : retourne true si le fichier a été trouvé */
        bool existe(const char * path, const char *file);

        /**  @brief Arborescence de la version en cours */
        Arborescance * newArbre;

        /** @brief permet de stocker les hash des fichies afin de les comparer */
        std::map<Sha512, PairHash> listeHash;

        /** @brief permet de remplir listeHash avec les anciens fichiers */
        void remplirAnciens(Arborescance *, Arborescance::Maillon *);

        /** @brief permet de remplir listeHash avec les nouveaux fichiers */
        void remplirNouveaux(Arborescance *, Arborescance::Maillon *);

        /** @brief Permet d'enregistrer et de concaténer des messages d'erreurs */
        std::string erreur;

        friend class Arborescance;
    };
}
#endif // VERSIONFILE_H
