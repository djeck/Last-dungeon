#include <sys/stat.h>
#include <sstream>
#include <cstdio>
#include <iostream>

#include "versionfile.h"
#include "UnixWindows.h"

namespace LD
{
    VersionFile::VersionFile()
    {
    }

    std::string VersionFile::Create(const char * path, const char *destination, const char * repProjet, Arborescance * arbre, bool lisible)
    {
        erreur = "";
        existe(path, destination);
        newArbre = new Arborescance(repProjet);
        if(! newArbre->arbre)
        {
            delete newArbre;
            return "Le chemin specifie pour la nouvelle version est invalide.";
        }
        /* pour avoir un apperçut de l'arborescence traitée en cas de bugs :
        std::cout << *(newArbre->arbre) << std::endl;
        char c;
        std::cin >> c; */

        //on commence par stocker chaque fichier en fonction du hash.
        listeHash.clear();
        if(arbre)
            arbre->parcours<VersionFile>(this, &VersionFile::remplirAnciens);
        if(newArbre)
            newArbre->parcours<VersionFile>(this, &VersionFile::remplirNouveaux);

        //on détermine tout les fichiers normaux à supprimer et à créer.
        std::list<Maillon *> listeSupressionFichier;
        std::list<Maillon *> listeCreationFichier;
        std::map<Sha512, PairHash>::const_iterator const fin = listeHash.end();
        std::map<Sha512, PairHash>::iterator p = listeHash.end();
        for(;p!=fin;++p)
        {
            if(p->second.old)
                listeSupressionFichier.push_back(p->second.old);
            if(p->second.nouv)
                listeCreationFichier.push_back(p->second.nouv);
        }

        //Effectuer les suppressions de fichiers (older), on met true
        //Si hash =, tableau de conversion et vice/versa.
        //On met true aux fichiers hash =, même nom et même dossier (les deux côtés)

        //Parcours des dossiers olders (à partir des feuilles) et selon le contenu rajout dans un tableau [deplacement], on met true aux deux.
        //Si déjà true, on regarde si le déplacement vaut la peine, si oui on modifie sinon on change.
        //deplacement[Maillon * new] = Maillon * older;
        //regarder fichier true pour savoir si suppression ou déplacements
        //mettre fichiers concernés à true;

        //rechercher des dossier à supprimer/créer

        //recherche des fichiers à déplacer

        //recherche versions fichiers(?) [suppression][Creation]

        char c;
        std::cin >> c;
        listeHash.clear();

        delete newArbre;
        return erreur;
    }

    std::string VersionFile::Create(const char * path, const char *destination, const char *source)
    {
        existe(path, destination);
        //TODO traductions
        return "";
    }

    bool VersionFile::existe(const char * path, const char * file)
    {
        struct stat info;
        std::string fichier = path;
        symboleDossier(fichier);
        fichier += file;
        if(stat(fichier.c_str(), &info) )
            return false;
        unsigned int i = 0;
        std::string newFile = path;
        symboleDossier(newFile);
        newFile += "save";
        while(1)
        {
           ++i;
           std::stringstream save(newFile);
           save << i;
           const char * tmp = save.str().c_str();
           if(stat(tmp, &info) )
           {
               rename(fichier.c_str(), tmp );
               break;
           }
        }
        return true;
    }

    void VersionFile::remplirAnciens(Arborescance *, Arborescance::Maillon * maillon)
    {
        //insersion dans une map <Sha512, structure<maillon *, bool> * >
        if( maillon->hash )
            //l'ancienne version est forcément correcte sinon elle n'aurait pas été enregistrée.
            listeHash[*maillon->hash].old = maillon;
    }

    void VersionFile::remplirNouveaux(Arborescance *, Arborescance::Maillon * maillon)
    {
        //on regarde dans la map, si pas présent, création, si bool = true : recherche du plus adapté.
        //Sinon duo [][]
        // /!\ liste de structure
        //A la fin, recherche des supressions.
        if( maillon->hash )
        {
            Arborescance::Maillon * tmp = listeHash[*maillon->hash].nouv;
            if(tmp)//Deux fichiers ont le même contenu, c'est soit le signe d'une collision entre deux hashs (suffisement rare pour être plus qu'improbable) soit une erreur dans le dossier
            {
                std::cout << "Erreur" << std::endl;
                erreur = "Deux fichiers :\n";
                erreur += maillon->path;
                erreur += maillon->nom;
                erreur += "\n";
                erreur += listeHash[*maillon->hash].nouv->path;
                erreur += listeHash[*maillon->hash].nouv->nom;
                erreur += "\nOn le même hash. Le dernier fichier cité ne sera pas pris en compte, nous vous recommandons de générer une version lisible et de le modifier manuellement si cet évènement est volontaire\n\n";
                //On ne prendra pas en compte ce maillon, à l'utilisateur de déterminer ce qu'il veut vraiment faire
                tmp->contenant->contenu.remove(tmp);
                delete(tmp);
            }
            listeHash[*maillon->hash].nouv = maillon;
        }
    }
}
