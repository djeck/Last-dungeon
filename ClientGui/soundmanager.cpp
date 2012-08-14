#include "soundmanager.h"

namespace LD
{
    SoundManager::SoundManager()
    {
    }
    sf::Music * SoundManager::addMusic(const std::string & nom)
    {
        ListeMusique::iterator p = listeMusique.find(nom);
        if( p != listeMusique.end() )
            return p->second;
        return listeMusique[nom] = new sf::Music;
    }

    sf::Music * SoundManager::addMusic(const std::string & nom, const std::string & fichier)
    {
        ListeMusique::iterator p = listeMusique.find(nom);
        if( p != listeMusique.end() )
            return p->second;
        sf::Music * ptr= new sf::Music;
        listeMusique[nom] = ptr;
        ptr->openFromFile(fichier);
        return ptr;
    }


    sf::SoundBuffer * SoundManager::addSon(const std::string & nom)
    {
        ListeSons::iterator p = listeSons.find(nom);
        if( p != listeSons.end() )
            return p->second;
        return listeSons[nom] = new sf::SoundBuffer;
    }


    sf::SoundBuffer * SoundManager::addSon(const std::string & nom, const std::string & fichier)
    {
        ListeSons::iterator p = listeSons.find(nom);
        if( p != listeSons.end() )
            return p->second;
        sf::SoundBuffer * ptr= new sf::SoundBuffer;
        listeSons[nom] = ptr;
        ptr->loadFromFile(fichier);
        return ptr;
    }

    sf::Music * SoundManager::getMusic(const std::string & nom)
    {
        ListeMusique::iterator p= listeMusique.find(nom);
        if( p != listeMusique.end() )
            return p->second;
        return NULL;
    }

    sf::SoundBuffer * SoundManager::getSon(const std::string & nom)
    {
        ListeSons::iterator p = listeSons.find(nom);
        if( p != listeSons.end() )
            return p->second;
        return NULL;
    }


    void SoundManager::deleteMusique(const std::string & nom)
    {
        ListeMusique::iterator p = listeMusique.find(nom);
        if( p != listeMusique.end() )
        {
            delete p->second;
            listeMusique.erase(p);
        }
    }

    void SoundManager::deleteSon(const std::string & nom)
    {
        ListeSons::iterator p = listeSons.find(nom);
        if( p != listeSons.end() )
        {
            delete p->second;
            listeSons.erase(p);
        }
    }


    void SoundManager::clearSon(void)
    {
        ListeSons::iterator p = listeSons.begin();
        for( ;p != listeSons.end() ; ++p)
        {
            delete p->second;
            listeSons.erase(p);
        }
    }


    void SoundManager::clearMusique(void)
    {
        ListeMusique::iterator p = listeMusique.begin();
        for( ; p != listeMusique.end() ; ++p)
        {
            delete p->second;
            listeMusique.erase(p);
        }
    }
}
