#ifndef PLATEAU_H
#define PLATEAU_H

#include <vector>
#include "Groupe.h"

namespace LD
{
	class Plateau
	{
		public :
			/** @brief construit un plateau de jeux pour le Go
				@param tailleX largeur du plateau 
				@param tailleY hauteur du plateau */
			Plateau(int tailleX, int tailleY);
			/** @brief Permet l'affichage du plateau de Go
				@return retourne une référence constante sur le damier*/
			const std::vector<Groupe *> & afficher(void) const;
		private :
			/** @brief largeur du plateau de jeux de Go */
			int tailleX;
			/** @brief hauteur du plateau de jeux de Go */
			int tailleY;
			/** @brief damier du plateau, chaque élément est un pointeur vers le groupe du pion. Un pointeur NULL signifie que la case est inoccupée */
			std::vector<Groupe *> damier;
	};
}

#endif
