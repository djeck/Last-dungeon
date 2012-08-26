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
        /* pour avoir un apper�ut de l'arborescence trait�e en cas de bugs :
        std::cout << *(newArbre->arbre) << std::endl;
        char c;
        std::cin >> c; */

        //on commence par stocker chaque fichier en fonction du hash.
        listeHash.clear();
        if(arbre)
            arbre->parcours<VersionFile>(this, &VersionFile::remplirAnciens);
        if(newArbre)
            newArbre->parcours<VersionFile>(this, &VersionFile::remplirNouveaux);

        //on d�termine tout les fichiers normaux � supprimer et � cr�er.
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
        //On met true aux fichiers hash =, m�me nom et m�me dossier (les deux c�t�s)

        //Parcours des dossiers olders (� partir des feuilles) et selon le contenu rajout dans un tableau [deplacement], on met true aux deux.
        //Si d�j� true, on regarde si le d�placement vaut la peine, si oui on modifie sinon on change.
        //deplacement[Maillon * new] = Maillon * older;
        //regarder fichier true pour savoir si suppression ou d�placements
        //mettre fichiers concern�s � true;

        //rechercher des dossier � supprimer/cr�er

        //recherche des fichiers � d�placer

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
            //l'ancienne version est forc�ment correcte sinon elle n'aurait pas �t� enregistr�e.
            listeHash[*maillon->hash].old = maillon;
    }

    void VersionFile::remplirNouveaux(Arborescance *, Arborescance::Maillon * maillon)
    {
        //on regarde dans la map, si pas pr�sent, cr�ation, si bool = true : recherche du plus adapt�.
        //Sinon duo [][]
        // /!\ liste de structure
        //A la fin, recherche des supressions.
        if( maillon->hash )
        {
            Arborescance::Maillon * tmp = listeHash[*maillon->hash].nouv;
            if(tmp)//Deux fichiers ont le m�me contenu, c'est soit le signe d'une collision entre deux hashs (suffisement rare pour �tre plus qu'improbable) soit une erreur dans le dossier
            {
                std::cout << "Erreur" << std::endl;
                erreur = "Deux fichiers :\n";
                erreur += maillon->path;
                erreur += maillon->nom;
                erreur += "\n";
                erreur += listeHash[*maillon->hash].nouv->path;
                erreur += listeHash[*maillon->hash].nouv->nom;
                erreur += "\nOn le m�me hash. Le dernier fichier cit� ne sera pas pris en compte, nous vous recommandons de g�n�rer une version lisible et de le modifier manuellement si cet �v�nement est volontaire\n\n";
                //On ne prendra pas en compte ce maillon, � l'utilisateur de d�terminer ce qu'il veut vraiment faire
                tmp->contenant->contenu.remove(tmp);
                delete(tmp);
            }
            listeHash[*maillon->hash].nouv = maillon;
        }
    }
}
