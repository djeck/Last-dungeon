#ifndef Jeux_H
#define Jeux_H
#include <iostream>
#include <SFML/System.hpp>
#include <stack>
#include "Fenetre.h"

namespace LD
{
	/** @brief Cette classe représente la fenêtre principale de jeux et l'interface joueur/programme */
	class Jeux
	{
		private:
			/** @brief icône de la fenêtre */
			sf::Image icone;
			/** @brief thread de récupération des évènements */
			sf::Thread Thread;
			/** @brief nombre de fenetres maximales */
			const int NB_FEN_MAX;
			/** @brief nombre d'images maximales par secondes */
			const int IMG_PAR_SEC;
			/** @brief nombre de fenêtre actuel */
			int nb_fenetre;
			/** @brief pointeur vers la fenêtre au premier plan */
			Fenetre *tete;
			/** @brief pointeur vers la fenêtre servant de fond */
			Fenetre *fond;
			/** @brief booléen, s'il passe à false, arrête le jeux */
			bool continu;
			/** @brief fenêtre principale */
			sf::RenderWindow wind;
			/** @brief boucle de lecture d'évènement */
			void event();
			/** @brief boucle d'affichage de la fenêtre principale */
			void afficher();
			/** @brief mutex servant à empêcher que deux thread ai la fenetre principale activée en même temps (provoque une erreur du serveur X) */
			sf::Mutex aff;
		public:
			/** @brief active la fenetre principale. Attention, contient un mutex
				@param bool act : Booléen indiquant si on active ou désactive la fenêtre principale (prendre ou libérer le mutex) */
			void setActive(bool act);
			/** @brief lance le jeux */
			void lancer();
			/** @brief créer une nouvelle fenêtre
				@param Fenetre * id : pointeur sur la fenêtre à ajouter
				@return bool : Booléen indiquant si l'ajout c'est bien passé */
			bool newFenetre(Fenetre *id);
			/** @brief ferme une fenêtre
				@param Fenetre *id : pointeur sur la fenêtre à fermer
				@return bool : Booléen indiquant si la fermeture c'est bien passée */
			bool closeFenetre(Fenetre *id);
			/** @brief ajoute une nouvelle fenêtre de fond et ferme l'ancienne fenêtre de fond s'il y en avait une
				@param Fenetre * new_fond : pointeur vers la nouvelle fenetre de fond */
			void setFond(Fenetre * new_fond);
			/** @brief construit un nouveau jeux.
				@param const std::string & titre : titre de la fenêtre principale (par défaut "sans titre")
				@param int tailleX : largeur de la fenêtre principale (par défaut 500)
				@param int tailleY : hauteur de la fenêtre principale (par défaut 500)
				@param int imageParSec : nombre d'image maximum par secondes (par défaut 60)
				@param int fenetreMax : nombre de fenêtre maximum (par défaut 20)
			*/
			Jeux(const std::string & titre = "sans titre", int tailleX = 500, int tailleY = 500, int imageParSec = 60, int fenetreMax = 20);
			/** @brief destructeur */
			~Jeux();
	};
}
#endif // Jeux_H
