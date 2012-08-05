#ifndef HFENETRE_H
#define HFENETRE_H
#include <iostream>
#include "Bouton.h"

namespace LD
{
   namespace Active
	{
		/** @brief fenetre non selectionner
			@see LD::Fenetre */
		const int SLEEP = 0;
		/** @brief sa fermeture a etait demander
			@see LD::Fenetre */
		const int KILLED = 1;
		/** @brief fenetre active
			@see LD::Fenetre */
		const int ACTIVE = 2;
		/** @brief fenetre surcharger
			@see LD::Fenetre */
		const int OVERLAOD = 4;
	}
	
	/** @brief Classe fenetre heriter de la classe bouton */
	class Fenetre : LD::Bouton
	{
		public :
		Fenetre(int etat = 0, CLASSE * classe = NULL, Fonction funct = NULL);
		  
		protected :
		
			
	};
}
#endif // HFENETRE_H

