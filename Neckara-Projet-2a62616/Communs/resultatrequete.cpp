#include "resultatrequete.h"

#include "stdlib.h"

namespace LD
{

    ColonneResultatRequete::ColonneResultatRequete(const LigneResultatRequete & ptr, int i) : ptr(ptr), i(i) {}

    const ColonneResultatRequete LigneResultatRequete::operator[](int i) const
    {
        return ColonneResultatRequete(*this, i);
    }    

    const MYSQL_ROW & LigneResultatRequete::operator=(MYSQL_ROW contenu)
    {
        return this->contenu = contenu;
    }

    const ColonneResultatRequete & ColonneResultatRequete::operator>>(int & cible) const
    {
        cible = atoi(ptr.contenu[i]);
        return *this;
    }

    const ColonneResultatRequete & ColonneResultatRequete::operator>>(std::string & cible) const
    {
        cible = ptr.contenu[i];
        return *this;
    }

    const ColonneResultatRequete & ColonneResultatRequete::operator>>(double & cible) const
    {
        cible = atof(ptr.contenu[i]);
        return *this;
    }

    const ColonneResultatRequete & ColonneResultatRequete::operator>>(unsigned long long int & cible) const
    {
        cible = strtoull(ptr.contenu[i], NULL, 10);
        return *this;
    }

    const ColonneResultatRequete & ColonneResultatRequete::operator>>(unsigned long int & cible) const
    {
        cible = strtoul(ptr.contenu[i], NULL, 10);
        return *this;
    }

    const ColonneResultatRequete & ColonneResultatRequete::operator>>(unsigned int & cible) const
    {
        cible = strtoul(ptr.contenu[i], NULL, 10);
        return *this;
    }


    const ColonneResultatRequete & ColonneResultatRequete::operator>>(unsigned short & cible) const
    {
        cible = strtoul(ptr.contenu[i], NULL, 10);
        return *this;
    }

    const ColonneResultatRequete & ColonneResultatRequete::operator>>(bool & cible) const
    {
        cible = (ptr.contenu[i][0] != '0');
        return *this;
    }
}

