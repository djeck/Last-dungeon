#include "../include/Logger.h"

namespace LD
{
	Logger::Logger(const std::string & chemin, const int taille):
	    chemin(chemin),
	    taille_max(taille),
	    valide(true),
	    temps_sec(time(NULL)),
	    temps(localtime(&temps_sec)),
	    nom(chemin)
	{
	    std::ostringstream oss;
	    oss << "_" << (temps->tm_year + 1900) << "_" << (temps->tm_mon + 1) << "_" << temps->tm_mday;
	    this->chemin += oss.str();
	    fichier.open(this->chemin.c_str(), std::ios::app);
	    if(!fichier) valide = false;
	}

	Logger::~Logger()
	{
	    fichier.close();
	}

	bool Logger::ecrire(const std::string & texte)
	{
	    const time_t temps_sec = time(NULL);
	    const struct tm * temps = localtime(&temps_sec);
	    std::ostringstream oss("[");
	    oss << temps->tm_hour << "h" << temps->tm_min << "m" << temps->tm_sec << "]";
	    const std::string date(oss.str());
	    const int taille(texte.size());

	    verrou.lock();
	    if(taille_actuelle +  taille + 10 >= taille_max)
	    {
		taille_actuelle = taille + 10;
		fichier << buffer;
		buffer = date + texte;
	    }
	    else
	    {
		taille_actuelle += taille + 10;
		buffer += date + texte;
	    }
	    verrou.unlock();

	    return true;
	}

	bool Logger::getValide()
	{
	    return valide;
	}

	bool Logger::ChangeDate()
	{
	    temps_sec = time(NULL);
	    temps = localtime(&temps_sec);
	    std::ostringstream oss;
	    oss << "_" << (temps->tm_year + 1900) << "_" << (temps->tm_mon + 1) << "_" << temps->tm_mday;
	    this->chemin = nom + oss.str();

	    verrou.lock();
	    fichier.close();
	    fichier.open(this->chemin.c_str(), std::ios::app);
	    if(!fichier) return false;
	    verrou.unlock();
	}
}
