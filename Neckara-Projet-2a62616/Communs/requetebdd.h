#ifndef REQUETEBDD_H
#define REQUETEBDD_H

#include "bdd.h"
#include "../Serveur/InterfaceReseau/infojoueur.h"

namespace LD
{
    /** @brief ensembles de requêtes à la base de donnée */
    namespace RequeteBDD
    {
        /** @brief Retourne le joueur correspondant au login envoyé en argument
            @param std::string login : login du joueur
            @param InfoJoueur * : retourne un pointeur sur les informations concernant le joueur */
        InfoJoueur * getJoueur(std::string login);

        /** @brief Retourne un pointeur vers un string expliquant pourquoi l'ip a été bannie
          Retourne NULL si l'ip n'est pas bannie
        @param std::string ip : ip à vérifier (IPv4 format 255.255.255.255)
        @param  std::string & raiso : raison du bannissement de l'ip (ou "" si l'ip n'est pas bannie)
        @return bool : true si l'ip est bannie, false sinon */
        bool isBanni(std::string ip, std::string & raison);

        /** @brief Bloque un compte
          Rq : peut aussi servir à débloquer un compte
            @param  unsigned int id : identifiant du compte à bloquer
            @param const time_t & tempsdebann : timestamp à laquelle le compte sera débloqué
            @param std::string raison : raison du blocage
            @param  unsigned short nbEchec : nombre d'echec*/
        void setBloque(unsigned int id, const time_t & tempsdebann=0, std::string raison="", unsigned short nbEchec = 0);

        /** @brief Banni un compte.
            Rq : peut aussi servir à débannir un compte
            @param unsigned int id : identifiant du compte à bannir
            @param std::string raison : raison du bann
            @param bool bannir : indique si on banni (true) ou si on débanni (false) */
        void setBanni(unsigned int id, std::string raison="", bool bannir=true);

    }
}
#endif // REQUETEBDD_H
