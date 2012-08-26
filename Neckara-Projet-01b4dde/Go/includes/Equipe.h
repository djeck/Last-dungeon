#ifndef EQUIPE_H
#define EQUIPE_H

#include "Joueur.h"
#include <string>
#include <vector>
/** @brief Représente une équipe de joueur pour le jeux de Go */
class Equipe
{
	public :
		/** @brief Construit une équipe vide
			@param numero : Numéro de l'équipe
			@param nomEquipe : Nom de l'équipe
			@param komi : komi de l'équipe
		*/
		Equipe(const int numero, std::string  & nomEquipe, float komi);
		/** @brief Détruit une équipe */
		~Equipe();
		/** @brief Ajoute un joueur à l'équipe
			@param joueur : Joueur ajouté à l'équipe*/
		void addJoueur(Joueur * joueur);
	private :
		/** @brief numero du groupe */
		const int numero;
		/** @brief nom de l'équipe */
		std::string nom;
		/** @brief komi de l'équipe */
		float komi;
		/** @brief liste des joueurs de l'équipe */
		std::vector<Joueur *> listeJoueur;
};


#endif
