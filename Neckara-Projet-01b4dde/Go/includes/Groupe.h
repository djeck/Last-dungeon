#ifndef GROUPE_H
#define GROUPE_H

#include "Joueur.h"

namespace LD
{
	class Groupe
	{
		public :
			/** @brief Construit un groupe de pion pour le jeux de Go
				@param joueur : Joueur auquel appartient le groupe */
			Groupe(Joueur *joueur);
			/** @brief définie le groupe VIDE : zones où aucun pion n'est posé */
			static Groupe *  const VIDE;
			/** @brief Pointeur vers le Joueur constant auquel appartient le groupe de pion */
			const Joueur * joueur;
	};
	
}

#endif
