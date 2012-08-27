#ifndef JOUEUR_H
#define JOUEUR_H


/** @brief Représente un joueur pour le jeux de Go */
class Joueur
{
	public :
		/** @brief Construit un joueur
			@param handicap dont bénéficie le joueur */
		Joueur(int handicap);
	private :
		/** @brief handicap dont bénéficie le joueur */
		int handicap;
};


#endif
