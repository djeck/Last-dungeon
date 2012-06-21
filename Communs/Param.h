#ifndef PARAM_H
#define PARAM_H

#include<string>

namespace LD
{
    /** @brief Options relative à la classe BDD */
    namespace BDD_PARAM
    {
        /** @brief nomination pour les différentes Bases de Données ouvertes. Max est le nombre de BDD connues.
            Il doit toujours être à la fin de l'énumération */
        typedef enum{JOUEURS, MAX}IdBDD;

        /** @brief donne les adresses où trouver les différentes tables */
        extern const char * const ADRESSE[MAX];


        /** @brief donne les logins à utiliser pour les différentes tables */
        extern const char * const LOGIN[MAX];

        /** @brief donne les mots de passes pour les différentes tables */
        extern const char * const PASSWORD[MAX];

        /** @brief donne les noms des tables auxquelles se connecter */
        extern const char * const TABLE[MAX];

        /** @brief nombre de caractère d'injections répertorié */
        extern const int NB_CARACTERES_INJECTIONS;

        /** @brief caractères utilisé pour les injections SQL */
        extern const char CARACTERES_INJECTIONS[];

        /** @brief Pour chaque caractère de  CARACTERES_INJECTIONS indique par quoi le remplacer */
        extern const std::string CARACTERES_INJECTIONS_R[];
    }

    /** @brief Options relative au fichier de log */
    namespace LOGGER_PARAM
    {
        /** @brief nomination des différents fichiers de logs. MAX est le nombre de fichiers de logs connus. Il doit toujours être placé à la fin */
        typedef enum{DEFAULT, ADMINISTRATEUR, MAX}IdLog;


            /** @brief donne les chemins où écrire les différents fichiers de logs */
            extern const char * const CHEMIN[MAX];


            /** @brief donne les tailles des buffers pour les différents fichiers de logs */
            extern const int TAILLE_BUFFER[MAX];
    }
//permet de compiler un client administrateur.
#ifdef ADMIN
    /** @brief options relative à l'administration, disponible uniquement si on compile le serveur ou un client administrateur */
    namespace ADMINISTRATEUR_PARAM
    {
        /** @brief port d'écoute pour les connexions administrateur */
        extern const int PORT;

        /** @brief Temps d'attente après X echecs en secondes */
        extern const unsigned int ATTENTE;

        /** @brief Nombres d'echecs consécutifs après lequel il faut attendre */
        extern const int NB_MAX_ECHEC;
    }
#endif
    /** @brief Options relatives au sha512, il est conseillé de changer le sel */
    namespace SHA512_PARAM
    {
        /** @brief sel utilisé dans le sha512 */
        extern const char SEL;
    }

    /** @brief Définis les constantes servant de paramètres aux switchs redirigeant les paquets vers les bonnes fonctions */
    namespace TRAITEMENT_PARAM
    {
        /** @brief Définis les constantes relatives aux types de traitements primaires
                @enum ADMINISTRATION : traitements relatifs à l'administration
                @enum CONNEXION : traitements relatifs à la connexion */
        enum{ADMINISTRATION, CONNEXION};

        /** @brief Défini les constantes relatives à la connexions */
        namespace CONNEXION_C
        {
            /** @brief Constantes relatives à la connexion
                @enum IPBAN : l'ip utilisée est bannie
                @enum FAUXID : le login ou le mot de passe est faux
                @enum BANNI : le compte du joueur a été banni
                @param BLOQUE : le compte est bloque
                @param DEJACO : le joueur est déjà connecté */
            enum{IPBAN, FAUXID, BANNI, BLOQUE, DEJACO};
        }
    }

    /** @brief Namespace relatif aux droits accordé à une personne */
    namespace DROITS
    {
        /** @brief Défini le numéro de bit associé au droit
            @enum ACCES : droit de se connecter au panneau d'administration */
        enum{ACCES};
    }
}

#endif // PARAM_H
