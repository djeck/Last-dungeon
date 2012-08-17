#ifndef LOGGER_H
#define LOGGER_H

#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <sstream>
#include <fstream>

#include "Param.h"

namespace LD
{
        /** @brief classe permettant de créer des logs. Il ne peut y avoir qu'une seule instance de cette classe. Si on souhaite construire d'autres logs, il faut créer des classes qui hériteroont de celle-ci.
            Les parametres sont disponibles dans LOGGER_PARAM
            /!\ Le fichier de log peut s'ouvrir n'importe où dans le programme, mais il doit se fermer de préférence à la fin du programme */
        class Logger
        {
            public:

            /** @brief Permet d'ecrire dans le fichier de log. Ouvre le fichier de log si inexistant
                    @param const std::string & texte : texte à écrire
                    @param LOGGER_PARAM::IdLog id : identifiant du fichier de log
                    @return bool : Booléen indiquant si l'écriture c'est bien passée (true) ou non (false) */
            static bool addLog(const std::string & texte, LOGGER_PARAM::IdLog id = LOGGER_PARAM::DEFAULT, bool force = false);


            /** @brief permet de changer de fichier de log (date de log). Ouvre le fichier de log si inexistant
                    @return bool : Booléen indiquant si on a changé de jour (true) ou non (false) */
            static bool newFileLog(LOGGER_PARAM::IdLog id = LOGGER_PARAM::DEFAULT);

                /** @brief Permet de détruire TOUTES les instances de Logger */
                static void closeLog(void);

            protected:
            private:


                /** @brief Permet d'obtenir l'instance de Logger, si aucune instance existe, créé l'instance.
                  Retourne NULL si il y a eu une erreur lors de la création ou de l'ouverture du fichier.
                    @param  const std::string & chemin : chemin du fichier de log. Le chemin est celui indiqué lors de la première instanciation
                    @param  const int taille : taille du buffer pour le fichier de log. */
                static bool openLog(LOGGER_PARAM::IdLog id);


                /** @brief Permet de construire un log
                        @param const std::string & chemin : nom du fichier qui contiendra les logs (le nom du fichier sera suivie du jour)
                        @param const int taille : taille maximal du buffer (500) */
                Logger(const std::string & chemin, const int taille);


                /** @brief destructeur */
                virtual ~Logger();


                /** @brief Interdit la construction d'un fichier de log par copie */
                Logger(const Logger & clone);



                /** @brief Permet d'ecrire dans le fichier de log
                        @param const std::string & texte : texte à écrire
                        @param : force l'écriture sans se soucier de la taille du buffer
                        @return bool : Booléen indiquant si l'écriture c'est bien passée (true) ou non (false) */
                bool ecrire(const std::string & texte, bool force = false);


                /** @brief permet de changer de fichier de log en fonction du jour  */
                void changeDate();


                /** @brief flux d'écriture pour le fichier de log */
                std::ofstream fichier;


                /** @brief chemin d'écriture */
                std::string chemin;


                /** @brief taille maximal du buffer */
                const int taille_max;


                /** @brief buffer d'écriture */
                std::string buffer;


                /** @brief date pour le changement de jour */
                time_t temps_sec;


                /** @brief structure de temps pour le changement de jour */
                struct tm * temps;


                /** @brief nom du fichier */
                const std::string nom;


                /** @brief taille du buffer actuel */
                int taille_actuelle;


                /** @brief verrou pour éviter d'écrire en même temps dans les logs */
                static sf::Mutex verrou[LOGGER_PARAM::MAX];


                /** @brief Contients toutes les instances de Logger */
                static std::vector<Logger *> instance;
        };
}
#endif
