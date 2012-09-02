#ifndef MENUBASH_H
#define MENUBASH_H

#include <string>

namespace LD
{
    /** @brief Menu avec un interface Shell pour le programme générant les données utilisées pour la mise à jour */
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

        /** @brief Génère une version lisible pour un être humain */
        void makeLisible(void);

        /** @brief Gestion des paramètres */
        void param(void);

        /** @brief efface l'écran */
        void clear(void);

        /** @brief Paramètres */
        std::string var[3];

        /** @brief sauvegarde les paramètres */
        void save(void);

        /** @brief charge les paramètres */
        void load(void);
    };
}
#endif // MENUBASH_H
