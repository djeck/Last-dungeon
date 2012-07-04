#ifndef INFOJOUEUR_H
#define INFOJOUEUR_H

#include "../../Communs/bdd.h"

namespace LD
{

    class InfoJoueur
    {
    public:
        /** @brief Construit un joueur
          @param const unsigned int id : identifiant du joueur
          @param const unsigned long long bloque : timestamp de la date où le compte sera débloqué
          @param const unsigned int droits : défini les droits du joueur (un bit à 1 signifie qu'il a le droit, un bit à 0 signifie qu'il ne possède pas de droits)
          @param const bool banni : indique si le joueur est banni
          @param const std::string raisonBan : indique la raison du bannissement ou du blocage
          @param const unsigned short echec : indique le nombre de tentative de connexion infructueuses depuis la dernière connexion réussie
          @param const std::string hash : hash du mot de passe du joueur */
        InfoJoueur(const unsigned int id, const unsigned long long bloque, const unsigned int droits,
                   const bool banni, const std::string & raisonBan, unsigned short echec, const std::string & hash);
    private :
            /** @brief identifiant du joueur*/
                    const unsigned int id;
            /** @brief timestamp de la date où le compte sera débloqué */
                    const unsigned long long bloque;
            /** @brief défini les droits du joueur (un bit à 1 signifie qu'il a le droit, un bit à 0 signifie qu'il ne possède pas de droits) */
                    const unsigned int droits;
            /** @brief indique si le joueur est banni */
                    const bool banni;
            /** @brief indique la raison du bannissement ou du blocage */
                    const std::string raisonBan;
            /** @brief indique le nombre de tentative de connexion infructueuses depuis la dernière connexion réussie */
                    unsigned short echec;
            /** @brief hash du mot de passe du joueur */
                    const std::string hash;

                    friend class Traitement;
    };
}

#endif // INFOJOUEUR_H
