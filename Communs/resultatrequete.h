#ifndef RESULTATREQUETE_H
#define RESULTATREQUETE_H

#include <mysql/mysql.h>
#include <iostream>
#include <ctime>

namespace LD
{
    class ColonneResultatRequete;

    /** @param Correspond à une ligne de la réponse à la requête SQL*/
    class LigneResultatRequete
    {
        public :
                /** @brief permet d'accéder à une colonne de la ligne
                    @param int i : numéro de la colonne (commence par 0)
                    @return const ColonneResultatRequete : colonne demandée*/
            const ColonneResultatRequete operator[](int i) const;
        /** @brief méthode permettant de remplir une ligne
            @param MYSQL_ROW contenu : ligne de la réponse à la requete SQL
            @return  const MYSQL_ROW & : ligne de la réponse à la requete SQL*/
            const MYSQL_ROW & operator=(MYSQL_ROW contenu);


        private :
        /** @brief ligne de données mysql */
            MYSQL_ROW contenu;
        /** @brief permet de faciliter les interractions */
            friend class ColonneResultatRequete;
    };
    /** @brief Correspond à une colonne de la ligne d'une réponse à la requête SQL*/
    class ColonneResultatRequete
    {
        public :
                /** @brief Permet de remplir un int à partir de la colonne */
            const ColonneResultatRequete & operator>>(int &) const;
        /** @brief Permet de remplir un unsigned long long int à partir de la colonne */
        const ColonneResultatRequete & operator>>(unsigned long long int &) const;
        /** @brief Permet de remplir un unsigned long int à partir de la colonne */
        const ColonneResultatRequete & operator>>(unsigned long int &) const;
        /** @brief Permet de remplir un unsigned int à partir de la colonne */
        const ColonneResultatRequete & operator>>(unsigned int &) const;
        /** @brief permet de remplir un unsigned short à partir de la colonne */
        const ColonneResultatRequete & operator>>(unsigned short &) const;
        /** @brief permet de remplir un std::string à partir de la colonne */
            const ColonneResultatRequete & operator>>(std::string &) const;
            /** @brief permet de remplir un double à partir de la colonne */
            const ColonneResultatRequete & operator>>(double &) const;
            /** @brief permet de remplir un bool à partir de la colonne */
            const ColonneResultatRequete & operator>>(bool &) const;
        private :
            /** @brief permet de constuire une colonne
                @param const LigneResultatRequete & ptr : Ligne à laquelle appartient la colonne
                @param int i : numéro de la colonne.
                */
            ColonneResultatRequete(const LigneResultatRequete & ptr, int i);
            /** @brief Ligne à laquelle appartient la colonne */
            const LigneResultatRequete & ptr;
            /** @brief numéro de la colonne */
            int i;
            /** @brief permet de faciliter les interractions */
            friend class LigneResultatRequete;
    };

}

#endif // RESULTATREQUETE_H
