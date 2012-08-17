#ifndef GO_H
#define GO_H

#include "Equipe.h"
#include "Plateau.h"
#include <vector>

namespace LD
{

	class Go
	{
		public :
			/** @brief Construit un nouveau jeux de Go
				@param listeEquipe : liste des équipes qui vont s'affronter
				@param tailleX : largeur du plateau (par défaut 19)
				@param tailleY : hauteur du plateau (par défaut 19)
				@param tmpMaxTour : temps maximum pour jouer par joueur par tour (par défaut 0)
				@param tourMax : nombre maximum de tour (par défaut 0)
)				@param tmpMax : temps maximum total (par défaut 0) */
			Go(std::vector<Equipe *> & listeEquipe, int tailleX = 19, int tailleY = 19, unsigned int tmpMaxTour = 0, unsigned int tourMax = 0, unsigned int tmpMax = 0);
			/** @brief Permet l'affichage du plateau de Go
				@return retourne une référence constante sur le damier*/
			const std::vector<Groupe *> & afficher(void) const;
		private :
			/** @brief liste des équipes qui vont s'affronter */
			std::vector<Equipe *> listeEquipe;
			/** @brief Temps maximum pour jouer par joueur par tour (par défaut 0) */
			unsigned int tmpMaxTour;
			/** @brief nombre maximum de tour (par défaut 0) */
			unsigned int tourMax;
			/** @brief Temps maximum total (par défaut 0) */
			unsigned int tmpMax;
			/** @breif Plateau de jeux pour le Go */
			Plateau plateau;
	};

}
#endif
