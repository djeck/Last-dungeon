#include "bdd.h"
#include <string.h>

namespace LD
{
    BDD::BDD(const char * adresse, const char * login, const char * password, const char * table)
    {
        bool exception(true);
        if(mysql_init(&conn) )
        {
            if(mysql_real_connect(&conn, adresse, login, password, table, 0, NULL, 0) )
                exception = false;
        }

        if(exception)
        {
            std::stringstream erreur;
            erreur << mysql_errno(&conn) <<  ": " << mysql_error(&conn);
            throw(erreur.str());
        }
    }

    MYSQL_RES * BDD::requete(const std::string & requete)
    {
        if(mysql_query(&conn, requete.c_str()) )
            return NULL;
       return mysql_store_result(&conn);
    }

    BDD::~BDD()
    {
            mysql_close(&conn);
    }

    std::vector<BDD *> BDD::listeBDD(BDD_PARAM::MAX, NULL);

    sf::Mutex BDD::verrou[BDD_PARAM::MAX];

    Resultat & BDD::requeteBDD(BDD_PARAM::IdBDD idBDD, const std::string & requete)
    {
        verrou[idBDD].lock();
        if(! listeBDD[idBDD]) //si la base de données n'est pas ouverte
            listeBDD[idBDD] = new BDD(BDD_PARAM::ADRESSE[idBDD], BDD_PARAM::LOGIN[idBDD], BDD_PARAM::PASSWORD[idBDD], BDD_PARAM::TABLE[idBDD]);

        MYSQL_RES * resultat = listeBDD[idBDD]->requete(requete);
        if(! resultat && mysql_errno(&listeBDD[idBDD]->conn) )
        {
            std::stringstream erreur;
            erreur << mysql_errno(&listeBDD[idBDD]->conn) <<  ": " << mysql_error(&listeBDD[idBDD]->conn);
            throw(erreur.str());
        }

        Resultat * final = new Resultat(resultat);

        mysql_free_result(resultat);
        verrou[idBDD].unlock();

        return *final;
    }



    Resultat::Resultat(MYSQL_RES * resultat) :
            nbLigne(resultat?mysql_num_rows(resultat):0 ),
            nbColonne(resultat?mysql_num_fields(resultat):0 ),
            resultat(resultat?new LigneResultatRequete[nbLigne]:0)
    {
        if(resultat)
        {
            LigneResultatRequete tmp;
            for(int i=0 ; ( tmp = mysql_fetch_row(resultat) ) ; ++i)
                this->resultat[i] = tmp;
        }
    }


    const LigneResultatRequete & Resultat::operator[](int i) const
    {
        return resultat[i];
    }


    Resultat::~Resultat()
    {
        delete resultat;
    }

    void BDD::closeBDD(BDD_PARAM::IdBDD idBDD)
    {
        verrou[idBDD].lock();
        if(listeBDD[idBDD])
        {
            delete listeBDD[idBDD];
            listeBDD[idBDD] = NULL;
        }
        verrou[idBDD].unlock();
    }

    void BDD::closeAllBDD()
    {
        for(int i=BDD_PARAM::MAX; i >= 0; --i)
        {
            verrou[i].lock();
            if(listeBDD[i])
            {
                delete listeBDD[i];
                listeBDD[i] = NULL;
            }
            verrou[i].unlock();
        }
    }


    std::string & BDD::antiInjection(std::string & chaine)
    {
        int taille = chaine.size();
        for(int p = 0; p != taille; ++p)
        {
            for(int i = 0; i != BDD_PARAM::NB_CARACTERES_INJECTIONS; ++i)
                if(chaine[p] == BDD_PARAM::CARACTERES_INJECTIONS[i])
                {
                    chaine.replace(p, 1, BDD_PARAM::CARACTERES_INJECTIONS_R[i]);
                    ++taille;
                    ++p;
                    break;
                }
        }
        return chaine;
    }
}
