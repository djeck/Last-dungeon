#ifndef LOGGER_H
#define LOGGER_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <sstream>
#include <fstream>

namespace LD 
{
	/** @brief classe permettant de créer des logs */
	class Logger
	{
	    public:
		/** @brief Permet de construire un log
			@param const std::string & chemin : nom du fichier qui contiendra les logs (le nom du fichier sera suivie du jour)
			@param const int taille : taille maximal du buffer (500) */
		Logger(const std::string & chemin, const int taille = 500);
		/** @brief Permet d'ecrire dans le fichier de log
			@param const std::string & texte : texte à écrire 
			@return bool : Booléen indiquant si l'écriture c'est bien passée (true) ou non (false) */
		bool ecrire(const std::string & texte);
		/** @brief destructeur */
		virtual ~Logger();
		/** @brief ??? */
		bool getValide();
		/** @brief permet de savoir si on change de jour ou non
			@return bool : Booléen indiquant si on a changé de jour (true) ou non (false) */
		bool ChangeDate();
	    protected:
	    private:
		/** @brief flux d'écriture pour le fichier de log */
		std::ofstream fichier;
		/** @brief ??? */
		bool valide;
		/** @brief buffer d'écriture */
		std::string buffer;
		/** @brief nom du fichier */
		const std::string nom;
		/** @brief chemin d'écriture */
		std::string chemin;
		/** @brief taille du buffer actuel */
		int taille_actuelle;
		/** @brief taille maximal du buffer */
		const int taille_max;
		/** @brief verrou pour éviter d'écrire en même temps dans les logs */
		sf::Mutex verrou;
		/** @brief date pour le changement de jour */
		time_t temps_sec;
		/** @brief structure de temps pour le changement de jour */
		struct tm * temps;
	};
}
#endif // LOGGER_H
