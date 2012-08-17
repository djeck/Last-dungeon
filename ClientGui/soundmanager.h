#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include<map>
#include<SFML/Audio.hpp>

namespace LD
{
/** @brief classe permettant de g�rer les sons et musiques */
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

        /** @brief Ajoute une musique � partir d'un fichier. /!\ Si la musique existe d�j�, elle ne sera pas recharg�e.
            @param const std::string & nom : nom de la musique
            @param const std::string & fichier : fichier de la musique
            @return sf::Music * : pointeur sur la nouvelle musique */
        sf::Music * addMusic(const std::string & nom, const std::string & fichier);


        /** @brief Ajoute un son
            @param const std::string & nom : nom du son
            @return sf::SoundBuffer * : pointeur sur le nouveau son */
        sf::SoundBuffer * addSon(const std::string & nom);


        /** @brief Ajoute un son � partir d'un fichier. /!\ Si le son existe d�j�, il ne sera pas recharg�.
            @param const std::string & nom : nom du son
            @param const std::string & fichier : fichier du son
            @return sf::SoundBuffer * : pointeur sur le nouveau son */
        sf::SoundBuffer * addSon(const std::string & nom, const std::string & fichier);


        /** @brief Retourne un pointeur sur la musique recherch�e
          @param const std::string & nom : musique recherch�e
          @return sf::Music * : pointeur sur la musique recherch�e, vaut NULL si non trouv�e */
        sf::Music * getMusic(const std::string & nom);

        /** @brief Retourne un pointeur sur le son recherch�
          @param const std::string & nom : son recherch�
          @return sf::Music * : pointeur sur le son recherch�, vaut NULL si non trouv�e */
        sf::SoundBuffer * getSon(const std::string & nom);


        /** @brief Supprime tous les sons */
        void clearSon(void);

        /** @brief Supprime toutes les musiques */
        void clearMusique(void);

        /** @brief Supprime toutes les musiques et tous les sons */
        void clearAll(void){ clearSon(); clearMusique(); }


        /** @brief Supprime un son en particulier, il est peu recommand� d'utiliser cette m�thode */
        void deleteSon(const std::string & nom);
        /** @brief Supprime une musique en particulier, il est peu recommand� d'utiliser cette m�thode */
        void deleteMusique(const std::string & nom);

    };
}

#endif // SOUNDMANAGER_H
