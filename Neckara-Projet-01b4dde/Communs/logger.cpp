#include "logger.h"

namespace LD
{

            Logger::Logger(const std::string & chemin, const int taille):
            chemin(chemin),
            taille_max(taille),
            temps_sec(time(NULL)),
            temps(localtime(&temps_sec)),
            nom(chemin)
        {
            std::ostringstream oss("_");
            oss << (temps->tm_year + 1900) << "_" << (temps->tm_mon + 1) << "_" << temps->tm_mday;
            this->chemin += oss.str();
            fichier.open(this->chemin.c_str(), std::ios::app);
        }


        Logger::Logger(const Logger & clone) : taille_max(clone.taille_max){ }

        Logger::~Logger()
        {
            fichier.close();
        }

        bool Logger::ecrire(const std::string & texte, bool force)
        {
            const time_t temps_sec = time(NULL);
            const struct tm * temps = localtime(&temps_sec);
            std::ostringstream oss("[");
            oss << temps->tm_hour << "h" << temps->tm_min << "m" << temps->tm_sec << "]";
            const std::string date(oss.str());
            const int taille(texte.size() + 10);
            if(force)
            {
                taille_actuelle = 0;
                buffer += date;
                buffer += texte;
                buffer += "\n";
                fichier << buffer;
                buffer = "";
            }
            else if(taille_actuelle >= taille_max)
            {
                taille_actuelle = taille;
                fichier << buffer;
                buffer = date;
                buffer += texte;
                buffer += "\n";
            }
            else
            {
                taille_actuelle += taille;
                buffer += date;
                buffer += texte;
                buffer += "\n";
            }

            return true;
        }


        void Logger::changeDate()
        {
            temps_sec = time(NULL);
            temps = localtime(&temps_sec);
            std::ostringstream oss("_");
            oss << (temps->tm_year + 1900) << "_" << (temps->tm_mon + 1) << "_" << temps->tm_mday;
            chemin = nom;
            chemin += oss.str();
            ecrire("Fermeture fichier log", true);
            fichier.close();
            fichier.open(this->chemin.c_str(), std::ios::app);
        }


        std::vector<Logger *> Logger::instance(LOGGER_PARAM::MAX, NULL);


        bool Logger::openLog(LOGGER_PARAM::IdLog id)
        {
            instance[id] = new Logger(LOGGER_PARAM::CHEMIN[id], LOGGER_PARAM::TAILLE_BUFFER[id]);
            if(! instance[id]->fichier)
            {
                delete instance[id];
                instance[id] = NULL;
            }

            return instance[id];
        }

        void Logger::closeLog()
        {
            for(int i=0; i != LOGGER_PARAM::MAX; ++i)
            {
                verrou[i].lock();
                if(instance[i])
                {
                    instance[i]->ecrire("Fermeture fichier log", true);
                    instance[i]->fichier.close();
                    delete instance[i];
                    instance[i] = NULL;
                }
                verrou[i].unlock();
            }     
        }

        sf::Mutex Logger::verrou[LOGGER_PARAM::MAX];



        bool Logger::addLog(const std::string & texte, LOGGER_PARAM::IdLog id, bool force)
        {
            verrou[id].lock();
            if(! instance[id])
                if(! openLog(id) )
                {
                    Logger::verrou[id].unlock();
                    return false;
                }

            instance[id]->ecrire(texte, force);
            verrou[id].unlock();
            return true;
        }


        bool Logger::newFileLog(LOGGER_PARAM::IdLog id)
        {
           verrou[id].lock();
           if(instance[id])
            {
               instance[id]->changeDate();
               if(! instance[id]->fichier)
               {
                   delete instance[id];
                   instance[id] = NULL;
               }
           }
           else
           {
               bool result(openLog(id));
               verrou[id].unlock();
               return result;
           }
           verrou[id].unlock();

            return instance[id];
        }
}
