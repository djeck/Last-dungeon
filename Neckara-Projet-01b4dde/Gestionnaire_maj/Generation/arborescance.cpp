#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
#include <fstream>
#include <iostream>

#include "arborescance.h"
#include "UnixWindows.h"

namespace LD
{
    typedef std::pair<std::string, Arborescance::Maillon *> DossierAttente;

    Arborescance::Arborescance(const char * path)
    {
        DIR *dir;
        struct dirent * fichier;
        Maillon * cible = NULL;
        struct stat st; 
        if( stat(path , &st) && ! S_ISDIR(st.st_mode) ) //si le chemin est invalide et ne désigne pas un dossier
        {
            arbre = NULL;
        }
        else
        {
            arbre = new Maillon("Root", path, NULL, NULL);
            DossierAttente dossier(path, arbre);
            std::list<DossierAttente> listeFichier(1, dossier);

            while(! listeFichier.empty() )
            {
                dossier = listeFichier.front();
                listeFichier.pop_front();
                cible = dossier.second;
                dir = opendir(dossier.first.c_str() );
                while( (fichier = readdir(dir) ) )
                {
                    if(! (strcmp(fichier->d_name, ".") && strcmp(fichier->d_name, "..")  ) )
                        continue;
                    std::string newPath = dossier.first;
                    symboleDossier(newPath);
                    newPath += fichier->d_name;
                    stat(newPath.c_str() , &st);
                    bool isDossier = S_ISDIR(st.st_mode);
                    Sha512 * hash = NULL;
                    if(! isDossier )
                    {
                        std::ifstream is(newPath.c_str() );
                        is.seekg (0, std::ios::end);
                        int length( is.tellg() );
                        is.seekg (0, std::ios::beg);
                        char buffer[length];
                        is.read (buffer,length);
                        std::string str( buffer, length);
                        hash = new Sha512(str);
                    }
                    Maillon * tmp = new Maillon(fichier->d_name, dossier.first, cible, hash);
                    cible->contenu.push_back(tmp);
                    if(isDossier)
                        listeFichier.push_back( DossierAttente(newPath , tmp) );
                }
                closedir(dir);
            }
        }
    }

    Arborescance::~Arborescance()
    {
        std::list<Maillon *> attente(1, arbre);
        if(arbre)
        {
            Maillon * cible;
            while(! attente.empty() )
            {
                cible = attente.front();
                attente.pop_front();
                if(! cible->isRegularFile() )
                    attente.insert(attente.end(), cible->contenu.begin(), cible->contenu.end() );
                delete cible;
            }
        }
    }

    Arborescance::Maillon::Maillon(const std::string & nom, const std::string & path, Maillon * contenant, Sha512 * hash)
        : nom(nom), path(path), hash(hash), contenant(contenant), traitement(true)
    {
    }

    Arborescance::Maillon::~Maillon()
    {
        if(hash)
            delete hash;
    }


    std::ostream & operator<<(std::ostream & sortie, Arborescance::Maillon & maillon)
    {
        sortie << "Chemin :" << maillon.path
               << "\nNom :" << maillon.nom
               << "\nType :" << ( (maillon.isRegularFile() )? "Fichier" : "Dossier" )
               << "\nDossier parent :";
       if( maillon.contenant)
          sortie << maillon.contenant->nom;
       if(maillon.hash)
          sortie << "\nHash :\n" << *maillon.hash;
        else
        {
            sortie << "\nContenu : " << std::endl;
            std::list<Arborescance::Maillon *>::const_iterator const fin = maillon.contenu.end();
            std::list<Arborescance::Maillon *>::const_iterator p = maillon.contenu.begin();
            for( ; p != fin; ++p)
                sortie << **p << std::endl;
            sortie << "Sortie du dossier : " << maillon.nom;
        }
        sortie << std::endl;
        return sortie;
    }


    /** @brief execute la fonction passée en argument pour chaque maillon */
    void Arborescance::parcours(void (*fct)(Arborescance *, Arborescance::Maillon *) )
    {
        std::list<Maillon *> attente(1, arbre);
        if(arbre)
        {
            Maillon * cible;
            while(! attente.empty() )
            {
                cible = attente.front();
                attente.pop_front();
                if(! cible->isRegularFile() )
                    attente.insert(attente.end(), cible->contenu.begin(), cible->contenu.end() );
                fct(this, cible);
            }
        }

    }

}
