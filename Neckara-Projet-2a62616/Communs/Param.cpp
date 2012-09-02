#include "Param.h"


namespace LD
{
    /** @brief Options relative à la classe BDD */
    namespace BDD_PARAM
    {

        /** @brief donne les adresses où trouver les différentes tables */
        extern const char * const ADRESSE[MAX] = {"localhost"};


        /** @brief donne les logins à utiliser pour les différentes tables */
        extern const char * const LOGIN[MAX] = {"root"};

        /** @brief donne les mots de passes pour les différentes tables */
        extern const char * const PASSWORD[MAX] = {"mdp"};

        /** @brief donne les noms des tables auxquelles se connecter */
        extern const char * const TABLE[MAX] = {"Projet"};

        /** @brief caractères utilisé pour les injections SQL */
        extern const char CARACTERES_INJECTIONS[] = {'\'', '"', 0x1A, '\n', '\r', '-', '\\', ';'};

        /** @brief Pour chaque caractère de  CARACTERES_INJECTIONS indique par quoi le remplacer */
        extern const std::string CARACTERES_INJECTIONS_R[] = {"\\'", "\\\"", "", "\\n", "\\r", "\\-", "\\\\", "\\;"};

        /** @brief nombre de caractère d'injections répertorié */
        extern const int NB_CARACTERES_INJECTIONS = 8;
    }

    /** @brief Options relative au fichier de log */
    namespace LOGGER_PARAM
    {

        /** @brief donne les chemins où écrire les différents fichiers de logs */
        extern const char * const CHEMIN[MAX] = {"erreur.log", "admin.log"};


        /** @brief donne les tailles des buffers pour les différents fichiers de logs */
        extern const int TAILLE_BUFFER[MAX] = {500, 500};
    }
//permet de compiler un client administrateur.
//#if ADMIN
    /** @brief options relative à l'administration, disponible uniquement si on compile le serveur ou un client administrateur */
    namespace ADMINISTRATEUR_PARAM
    {
        /** @brief port de connexion administrateur */
        extern const int PORT = 1111;

        /** @brief Temps d'attente après X echecs en secondes */
        extern const unsigned int ATTENTE = 10*60;

        /** @brief Nombres d'echecs consécutifs après lequel il faut attendre */
        extern const int NB_MAX_ECHEC = 3;
        extern const std::string MSG_BLOQUE = "Bien fait!";
    }
//#endif
    /** @brief options relatives au sha512 */
    namespace SHA512_PARAM
    {
        /** @brief sel utilisé dans le sha512 */
        extern const char SEL = 1<<7;
    }

    namespace CO_JOUEURS
    {
        extern const int NB_THREAD = 5;
        extern const unsigned int PORT = 1200;
        extern const unsigned int ATTENTE = 20;
        extern const int NB_MAX_ECHEC = 2;
        extern const std::string MSG_BLOQUE = "Bien fait!";

    }

}
