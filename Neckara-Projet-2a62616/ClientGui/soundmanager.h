#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include<map>
#include<SFML/Audio.hpp>

namespace LD
{
/** @brief classe permettant de gérer les sons et musiques */
    class SoundManager
    {
    public:
        SoundManager();
    private :
        typedef std::map<std::string, sf::SoundBuffer *> ListeSons;
        typedef std::map<std::string, sf::Music *> ListeMusique;

        /** @brief liste des sons */
        ListeSons listeSons;
        /** @brief liste des musiques */
        ListeMusique listeMusique;
    public :
        /** @brief Ajoute une musique
            @param const std::string & nom : nom de la musique
            @return sf::Music * : pointeur sur la nouvelle musique */
        sf::Music * addMusic(const std::string & nom);

        /** @brief Ajoute une musique à partir d'un fichier. /!\ Si la musique existe déjà, elle ne sera pas rechargée.
            @param const std::string & nom : nom de la musique
            @param const std::string & fichier : fichier de la musique
            @return sf::Music * : pointeur sur la nouvelle musique */
        sf::Music * addMusic(const std::string & nom, const std::string & fichier);


        /** @brief Ajoute un son
            @param const std::string & nom : nom du son
            @return sf::SoundBuffer * : pointeur sur le nouveau son */
        sf::SoundBuffer * addSon(const std::string & nom);


        /** @brief Ajoute un son à partir d'un fichier. /!\ Si le son existe déjà, il ne sera pas rechargé.
            @param const std::string & nom : nom du son
            @param const std::string & fichier : fichier du son
            @return sf::SoundBuffer * : pointeur sur le nouveau son */
        sf::SoundBuffer * addSon(const std::string & nom, const std::string & fichier);


        /** @brief Retourne un pointeur sur la musique recherchée
          @param const std::string & nom : musique recherchée
          @return sf::Music * : pointeur sur la musique recherchée, vaut NULL si non trouvée */
        sf::Music * getMusic(const std::string & nom);

        /** @brief Retourne un pointeur sur le son recherché
          @param const std::string & nom : son recherché
          @return sf::Music * : pointeur sur le son recherché, vaut NULL si non trouvée */
        sf::SoundBuffer * getSon(const std::string & nom);


        /** @brief Supprime tous les sons */
        void clearSon(void);

        /** @brief Supprime toutes les musiques */
        void clearMusique(void);

        /** @brief Supprime toutes les musiques et tous les sons */
        void clearAll(void){ clearSon(); clearMusique(); }


        /** @brief Supprime un son en particulier, il est peu recommandé d'utiliser cette méthode */
        void deleteSon(const std::string & nom);
        /** @brief Supprime une musique en particulier, il est peu recommandé d'utiliser cette méthode */
        void deleteMusique(const std::string & nom);

    };
}

#endif // SOUNDMANAGER_H
