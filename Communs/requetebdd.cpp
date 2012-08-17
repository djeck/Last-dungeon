#include "requetebdd.h"

namespace LD
{

    namespace RequeteBDD
    {

        InfoJoueur * getJoueur(std::string login)
        {
            InfoJoueur *ptr = NULL;
            BDD::antiInjection(login);
            Resultat & r = BDD::requeteBDD(BDD_PARAM::JOUEURS, "SELECT id, banni, raisonBan, Unix_Timestamp(bloque), HEX(password), echecConnexion, droits FROM Joueurs WHERE login='" + login + "'");
            if(r.nbLigne)
            {
                unsigned int id;
                unsigned long long bloque;
                unsigned int droits;
                bool banni;
                std::string raisonBan;
                unsigned short echec;
                std::string hash;
                r[0][0] >> id;
                r[0][1] >> banni;
                r[0][2] >> raisonBan;
                r[0][3] >> bloque;
                r[0][4] >> hash;
                r[0][5] >> echec;
                r[0][6] >> droits;
                ptr = new InfoJoueur(id, bloque, droits, banni, raisonBan, echec, hash);
            }
            delete &r;
            return ptr;
        }

        bool isBanni(std::string ip, std::string & raison)
        {
            BDD::antiInjection(ip);
            Resultat & r = BDD::requeteBDD(BDD_PARAM::JOUEURS, "SELECT raison FROM IpBannies WHERE ip='" + ip + "'");
            bool retour;
            if(! ( retour = r.nbLigne) )
                raison = "";
            else
                r[0][0] >> raison;
            delete &r;
            return retour;
        }

        void setBloque(unsigned int id, const time_t & tempsdebann, std::string raison, unsigned short nbEchec)
        {
            std::stringstream requete;
            requete << "UPDATE Joueurs SET raisonBan='"
                    << BDD::antiInjection(raison) << "'"
                    << ", bloque=FROM_UNIXTIME(" << tempsdebann
                    << "), echecConnexion=" << nbEchec << ""
                    << " WHERE id=" << id;
            delete & BDD::requeteBDD(BDD_PARAM::JOUEURS, requete.str() );
        }

        void setBanni(unsigned int id, std::string raison, bool bannir)
        {
            std::stringstream requete;
            requete << "UPDATE Joueurs SET raisonBan='"
                    << BDD::antiInjection(raison) << "'"
                    << ", banni=" << bannir
                    << " WHERE id=" << id;
            delete & BDD::requeteBDD(BDD_PARAM::JOUEURS, requete.str() );
        }
    }

}
