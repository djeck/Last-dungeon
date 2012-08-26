#include "../includes/Plateau.h"

#include <iostream>

namespace LD
{
	Plateau::Plateau(int tailleX, int tailleY) : tailleX(tailleX), tailleY(tailleY), damier(static_cast<int>(tailleX*tailleY), Groupe::VIDE)
	{

	}
	const std::vector<Groupe *> & Plateau::afficher(void) const
	{
		return damier;
	}
}


