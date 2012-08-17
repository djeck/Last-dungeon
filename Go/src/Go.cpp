#include "../includes/Go.h"

namespace LD
{

	Go::Go(std::vector<Equipe *> & listeEquipe, int tailleX, int tailleY, unsigned int tmpMaxTour, unsigned int tourMax, unsigned int tmpMax)
		: listeEquipe(listeEquipe),
		tmpMaxTour(tmpMaxTour),
		tourMax(tourMax),
		tmpMax(tmpMax),
		plateau(tailleX, tailleY)
	{
	
	}

	const std::vector<Groupe *> & Go::afficher(void) const
	{
		return plateau.afficher();
	}
}
