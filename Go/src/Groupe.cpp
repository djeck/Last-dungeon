#include "../includes/Groupe.h"

namespace LD
{
	Groupe * const Groupe::VIDE = 0;
	Groupe::Groupe(Joueur * joueur) : joueur(joueur)
	{

	}
}
