#ifndef HFENETRE_H
#define HFENETRE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Sprite.h"

namespace LD
{
	/** @brief Classe abstraite servant de base pour chacunes des fenêtres */
	class Fenetre
	{
		protected :
			/** @brief Booléen indiquant si la fenêtre désactive les fenêtres étant derrière elle */
			bool autreDesactive;
			/** @brief Booléen indiquant si les raccourcits claviers sont disponibles dans cette fenêtre */
			bool raccourcitClavier;
		public :
			/** @brief constructeur de la fenêtre */
			Fenetre(){};
			/** @brief destructeur de la fenêtre */
			virtual ~Fenetre(){};
			/** @brief méthode virtuelle déclanchée lorsque la fenêtre perds son focus */
			virtual void lost_focus(){};
			/** @brief retourne l'identifiant de la fenêtre (l'adresse de l'instance)
				@return Fenetre * : identifiant de la fenêtre (pointeur sur Fenetre) */
			Fenetre *getId();
			/** @brief méthode virtuelle donnant l'image de la fenêtre
				Rq : utiliser un sf::Rendertexture est très intéressant dans le cadre d'une fenêtre
				@return const Sprite : image de la fenêtre */
			virtual const Sprite getSprite();
			/** @brief Méthode virtuelle indiquant si une position est incluse ou non dans la fenêtre
				@param int x : position sur la largeur
				@param int y : position sur la hauteur
				@return bool : Booléen indiquant si la position est incluse (true) ou non (false) dans la fenêtre */
			virtual bool isNotTouch(int x, int y);
			/** @brief Méthode permettant de savoir si les raccourcit clavier sont activé dans cette fenetre
				@return bool : Booléen indiquant si les raccourcits claviers sont activés (true) ou non (false) */
			bool isRaccourcitClavier();
			/** @brief Méthode virtuelle permettant de donner un évènement à traiter par la fenêtre
				@param sf::Event &Event : évènement à traiter
			*/
			virtual void setEvent(sf::Event &Event){};
			/** @brief Méthode permettant de savoir si la fenêtre désactive les fenêtres étant derrière elle
				@return bool : Booléen indiquant si la fenêtre désactive les fenêtres étant derrière elle (true) ou non (false) */
			bool isAutreDesactive();
		private :
			/** @brief sous-classe de Fenetre permettant de ranger les fenêtre dans une liste circulaire doublement chaînée
				Rq : include toutes les fonctions de déplacements de fenêtres au sein de cette liste ici ? */		
			class Maillon
			{
				private :
					/** @brief pointeur vers la fenetre suivante */
					Fenetre * suivante;
					/** @brief pointeur vers la fenetre précédante */
					Fenetre * precedante;
				friend class Jeux;
			}maillon;
		friend class Jeux;
	};
}
#endif // HFENETRE_H
