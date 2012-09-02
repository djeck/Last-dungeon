#ifndef ARBORESCANCE_H
#define ARBORESCANCE_H

#include <list>
#include <string>

#include "../../Communs/sha512.h"

namespace LD
{
/** @brief repr�sente un ensemble de fichier et de dossier */
    class Arborescance
    {
    public:
        /** @brief permet d'obtenir une arborescence � partir du contenu d'un dossier */
        Arborescance(const char * path);

        //TODO via BDD
        /** @brief d�truit une arborescence */
        ~Arborescance();

        /** @brief Element de l'arborescence */
        class Maillon;

        /** @brief Arborescance */
        Maillon * arbre;

        /** @brief execute la fonction pass�e en argument pour chaque maillon */
        void parcours(void (*)(Arborescance *, Arborescance::Maillon *) );

        /** @brief execute la m�thode pass�e en argument pour chaque maillon */
        template<typename CLASSE>
        void parcours(CLASSE *, void(CLASSE::*)(Arborescance *, Arborescance::Maillon *) );
    };

    class Arborescance::Maillon
    {
        public :
        /** @brief Construit un maillon
          @param const std::string & nom : nom du fichier
          @param const std::string & path : chemin o� trouver le fichier
          @param Maillon * contenant : dossier contenant ce fichier
          @param Sha512 * hash : Pointeur sur le hash (sha512) du fichier. */
        Maillon(const std::string & nom, const std::string & path, Maillon * contenant, Sha512 * hash);

        ~Maillon();

        /** @brief nom du fichier */
            std::string nom;
            /** @brief chemin o� trouver le fichier */
            std::string path;
            /** @brief Pointeur sur le hash (sha512) du fichier.*/
            Sha512 * hash;

            /** @brief Indique si le fichier est un fichier normal ou un dossier */
            inline bool isRegularFile()
            {
                return hash;
            }

            /** @brief Indique si le fichier est un dossier */
            inline bool isDossier()
            {
                return hash;
            }

            /** @brief contenu du dossier */
            std::list<Maillon *> contenu;
            /** @brief dossier contenant ce fichier */
            Maillon * contenant;
            /** @brief indique si ce fichier doit �tre trait� */
            bool traitement;

            friend std::ostream & operator<<(std::ostream &, Arborescance::Maillon &);
    };
/** @brief affiche les donn�es d'un fichier */
    std::ostream & operator<<(std::ostream &, Arborescance::Maillon &);



    template<typename CLASSE>
    void Arborescance::parcours(CLASSE * classe, void(CLASSE::*meth)(Arborescance *, Arborescance::Maillon *) )
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
                (classe->*meth)(this, cible);
            }
        }
    }
}

#endif // ARBORESCANCE_H
