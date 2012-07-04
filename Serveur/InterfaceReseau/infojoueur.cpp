#include "infojoueur.h"

namespace LD
{
    InfoJoueur::InfoJoueur(const unsigned int id, const unsigned long long bloque, const unsigned int droits,
                           const bool banni, const std::string & raisonBan, unsigned short echec, const std::string & hash)
                               : id(id), bloque(bloque), droits(droits), banni(banni),
                               raisonBan(raisonBan), echec(echec), hash(hash)
    {
    }

}
