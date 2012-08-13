#ifndef MENUBASH_H
#define MENUBASH_H

#include <string>

namespace LD
{
    /** @brief Menu avec un interface Shell pour le programme g�n�rant les donn�es utilis�es pour la mise � jour */
    class MenuBash
    {
    public:
        MenuBash();

        /** @brief Lance le menu */
        void start(void);
    private :
        /** @brief affiche le menu */
        void affichage(void);

        /** @brief affiche un message d'erreur lorsque le choix n'est pas valide */
        void choixInvalide(char choix);

        /** @brief G�n�re une version lisible pour un �tre humain */
        void makeLisible(void);

        /** @brief Gestion des param�tres */
        void param(void);

        /** @brief efface l'�cran */
        void clear(void);

        /** @brief Param�tres */
        std::string var[3];

        /** @brief sauvegarde les param�tres */
        void save(void);

        /** @brief charge les param�tres */
        void load(void);
    };
}
#endif // MENUBASH_H
