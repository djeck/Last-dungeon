#ifndef TEST_H
#define TEST_H

#include "Equipe.h"
#include "Go.h"
#include <vector>
#include <string>
/** @brief classe permettant de tester le jeux de Go via une interface shell */

class Test
{
	public :
		/** @brief Constructeur */
		Test();
		/** @brief Destructeur */
		~Test();
		/** @brief méthode permettant d'entrer les options et les groupes */
		void iniNewGo(void);
		/** @brief méthode permettant de lancer une partie */
		void commencerPartie(void);		
	private :
		/** @brief Méthode permettant d'effectuer un tour lors du jeux de Go
			@param go : référence vers le jeux de Go */
		void tour(void);
		/** @brief Affiche le damier du jeux de Go
			@param go : référence vers le jeux de Go affiché */
		void afficher(const LD::Go & go);
		/** @brief Largeur du plateau de Go */
		int tailleX;
		/** @brief Hauteur du plateau de Go */
		int tailleY;
		/** @brief Temps maximum en secondes de jeux par joueur par tour*/
		unsigned int tmpMaxTour;
		/** @brief Temps maximum en secondes de jeux*/
		unsigned int tmpMax;
		/** @brief Nombre de tour maximum de jeux */
		unsigned int tourMax;

		/** @brief Méthode permettant l'ajout d'une équipe
			@param numEquipe numéro de l'équipe (commence par 0).
		*/
		void addEquipe(int numEquipe);
		/** @brief Liste des équipe */
		std::vector<Equipe *> listeEquipe;
		/** @brief méthode permettant d'ajouter un joueur
			@param numJoueur numéro du joueur dans l'équipe
			@return retourne un pointeur sur le joueur ajouté à l'équipe */
		Joueur * addJoueur(int numJoueur);
};
#endif
