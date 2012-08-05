#ifndef BOUTON_H
#define BOUTON_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include "Image.h"
#include "Sprite.h"

namespace LD
{
	/** @namespace Action
		@brief Namespace constenant les évènements pouvant déclancer une action
		Rq : Supprimer le namespace et les inclures en tant qu'attribut static constant dans LD::Bouton
		@see LD::Bouton */
	namespace Action
	{
		/** @brief Aucun évènement
			@see LD::Bouton */
		const int AUCUN = 0;
		/** @brief évènement clavier
			@see LD::Bouton */
		const int CLAVIER = 1;
		/** @brief On a cliqué sur le bouton
			@see LD::Bouton */
		const int SOURIS_CLIQUE = 2;
		/** @brief Le curseur est sur le bouton
			@see LD::Bouton */
		const int SOURIS_DESSUS = 4;
		/** @brief On a cliqué sur le bouton puis on a relaché le clique, toujours sur le bouton
			@see LD::Bouton */
		const int SOURIS_DECLIC = 8;
		/** @brief Le curseur était sur le bouton mais n'y est plus
			@see LD::Bouton */
		const int SOURIS_PARTIE = 16;
	}
	/** @namespace Etat
		@brief namespace contenant tous les états possibles d'un bouton
		Rq : Supprimer le namespace et les inclures en tant qu'attribut static constant dans LD::Bouton
		@see LD::Bouton */
	namespace Etat
	{
		/** @brief Lorsque le bouton est désactivé
			@see LD::Bouton */
		const int DESACTIVE = 1;
		/** @brief Lorsqu'on clique sur le bouton
			@see LD::Bouton */
		const int SOURIS_CLIQUE = 2;
		/** @brief Lorsque le curseur est sur le bouton
			@see LD::Bouton */
		const int SOURIS_DESSUS = 4;
		/** @brief Lorsque le bouton est normal
			@see LD::Bouton */
		const int NORMAL = 8;
	}
	/** @brief Classe Bouton. Un bouton peut avoir 4 états et avoir une image pour chacun de ces états. Il peut aussi déclencher une unique fonction suivant 5 évènements.

	Rq : Renommer cette classe NewBouton et créer une classe Bouton sans template dont héritera NewBouton ce qui permettra d'utiliser des pointeurs et des références plus générales
	*/
	template<typename CLASSE>
	class Bouton
	{
		/** @brief Fonction est le type correspondant à un pointeur sur une méthode de la classe CLASSE (template) */
	    typedef void (CLASSE::*Fonction)(Bouton &);
	    public:
		/** @brief Constructeur d'un bouton
			Rq : mettre sa définition à l'exterieur
			@param int etat : état initial du bouton
			Rq : créer 4 attributs static constants
			@param CLASSE * classe : classe à qui appartient la méthode qu'il faudra appeler (par défaut NULL).
			@param Fonction funct : pointeur sur la méthode qu'il faudra appeler (par défaut NULL)
			@param int config : Détermine les évènements qui déclencherons l'appel de la méthode. Par défaut : LD::Action::Aucun Utilisation : OPTION1 | OPTION2. @see LD::Action
			
		*/
		Bouton(int etat = 0, CLASSE * classe = NULL, Fonction funct = NULL, int config = LD::Action:Aucun):
			etat(etat),
			funct(funct),
			classe(classe),
			config(config),
			positionX(0),
			positionY(0){};

		//attributs publics :
		/** @brief Détermine les évènements qui déclencherons l'appel de la méthode, mis en attribut public car il n'y a aucune vérification à effectuer au niveau du setter. @see LD::Action
			
		*/
		int config;
		/** @brief Pointeur sur la méthode qu'il faudra appeler, mis en attribut public car il n'y a aucune vérification à effectuer au niveau du setter.

		*/
		Fonction funct;
		/** @brief Classe à qui appartient la méthode qu'il faudra appeler, mis en attribut public car il n'y a aucune vérification à effectuer au niveau du setter.
		*/
		CLASSE * classe;
		/** @brief état du bouton
			Rq : créer 4 attributs static constants :0 : désactive, 1 : onclick, 2 : onblur, 3 : normal; */
		int etat;
		/** @brief Permet d'associer une image à un ou plusieurs états du bouton
			@param LD::Image * const image : image à utiliser
			@param int pour : états pour lesquels il faudra utiliser l'image (par défaut LD::Etat::Desactive) utilisation : Etat1 | Etat2
			@param int x : ajustement en pixel de l'image sur la largeur relativement à la position du bouton (par défaut 0)
			@param int y : ajustement en pixel de l'image sur la hauteur relativement à la position du bouton (par défaut 0)*/
                void setImage(Image * const image, int pour = Etat::Desactive, int x = 0, int y = 0);
		/** @brief Méthode permettant d'obtenir l'image du bouton pour ensuite l'afficher
			@return const LD::Sprite & : image du bouton à afficher
		*/
		const Sprite &getImage(void);
		/** @brief Permet de modifier l'ajustement en pixel de l'image relativement à la position du bouton @see setImage
			@param const int x : valeur de l'ajustement sur la largeur
			@param const int y : valeur de l'ajustement sur la hauteur
			@param int pour : état(s) sur le(s)quel(s) l'ajustement porte (par défaut LD::Etat::Desactive) @see setImage
		*/
		void setPositionR(const int x, const int y, int pour = Etat::Desactive);
		/** @brief obtient la valeur de l'ajustement sur la largeur pour un état donné
		Rq : fusionner avec la fonction @see getPositionRX et retourner une structure
		Rq2 : pour le pour utiliser les même valeurs que @see Etat;
			@param int pour : état pour lequel on veut connaitre l'ajustement sur la largeur
			@return int : ajustement sur la largeur */
		int getPositionRX(int pour = 1);
		/** @brief obtient la valeur de l'ajustement sur la hauteur pour un état donné
		Rq : fusionner avec la fonction @see getPositionRY et retourner une structure
		Rq2 : pour le pour utiliser les même valeurs que @see Etat;
			@param int pour : état pour lequel on veut connaitre l'ajustement sur la hauteur
			@return int : ajustement sur la hauteur */
		int getPositionRY(int pour = 1);
		/** @brief Méthode permettant de modifier la position du bouton
			@param int positionX : nouvelle position sur la largeur du bouton
			@param int positionY : nouvelle position sur la hauteur du bouton */
		void setPosition(int positionX, int positionY);
		/** @brief Méthode permettant d'obtenir la position du bouton sur la largeur
			Rq : Fusionner avec @see getPositionY
			@return int : position sur la largeur du bouton
			@see getPositionY */
		int getPositionX(void);
		/** @brief Méthode permettant d'obtenir la position du bouton sur la hauteur
		Rq : Fusionner avec @see getPositionX
		@return int : position sur la hauteur du bouton
		@see getPositionX */
		int getPositionY(void);
		/** @brief méthode virtuelle permettant de traiter l'évènement passé en paramètre
			@param const sf::Event & event : évènement à traiter
			@return bool : setEvent retourne true si il est la cible de l'évènement, false sinon.
		*/
		virtual bool setEvent(const sf::Event & event); //traite l'évènement
		/** @brief méthode permettant de récupérer l'évènement traité par le bouton
			@return const sf::Event & : évènement traité par le bouton
		*/
		const sf::Event & getEvent();
		/** @brief Méthode retournant true si le bouton n'est pas désactivé, false sinon.
			@return bool : true si  le bouton n'est pas désactivé, false sinon. */
		bool isActive();
		/** @brief Méthode permettant d'activer/de désactiver le bouton
			@param bool active : true si on souhaite activer le bouton
			false si on souhaite le désactiver */
		void setActive(bool active);
	    protected:
		/** @brief Les quatres images pour les quatres états du bouton
		*/
		Sprite sprite[4];
		/** @brief évènement taité */
		sf::Event event;
		/** @brief position sur la largeur du bouton.
			Rq : utiliser une structure et fusionner avec positionY */
		int positionX;
		/** @brief position sur la hauteur du bouton.
			Rq : utiliser une structure et fusionner avec positionX */		
		int positionY;
		/** @brief position relative sur la largeur des quatres images par rapport à celle du bouton.
			Rq : utiliser une structure et fusionner avec positionRY */
		int positionRY[4];
		/** @brief position relative sur la hauteur des quatres images par rapport à celle du bouton.
			Rq : utiliser une structure et fusionner avec positionRX */
		int positionRX[4];
	};

	template<typename CLASSE>
        void Bouton<CLASSE>::setImage(Image * const image, int pour, int x, int y)
	{
		int i(0);
		while(i != 4)
		{
			if(pour%2)
			{
				if(image == NULL)
					sprite[i].setImageVide();				
				else
					sprite[i].setImage(*image);
				positionRX[i] = x;
				positionRY[i] = y;
			}
			pour /= 2;
			++i;
		}
	}


	template<typename CLASSE>
	const Sprite & Bouton<CLASSE>::getImage()
	{
	    if(sprite[etat].getImage() != NULL)
		return sprite[etat];
	    else if(sprite[3].getImage() == NULL)
		std::cerr << "/!\\L'image Normale du bouton doit être renseignée avant tout affichage!!!" << std::endl;
	    return sprite[3];
	}


	template<typename CLASSE>
	bool Bouton<CLASSE>:: setEvent(const sf::Event & event)
	{
		int image(etat);
		if(sprite[etat].getImage() == NULL)
			image = 3;
		this->event = event;
		if(etat == 0)//bouton désactivé
			return false;
		if(event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
		{
			if(config%2 == 1)
			{
				if(classe != NULL && funct != NULL) (classe->*(funct))(*this);
					return true;
			}
			return false;
		}
		if(event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased)
		{
			int x = event.mouseButton.x - sprite[image].getPosition().x;
			int y = event.mouseButton.y - sprite[image].getPosition().y;
			if(x < 0 || x >= sprite[image].getLocalBounds().width || y < 0 || y >= sprite[image].getLocalBounds().height)
			{
				    etat = 3;
				    return false;
			}
                        Image * test(sprite[image].getImage());
			if(test->getImage() == NULL)
			{
				test->textureToImage();
			}	
			if(test->getImage()->getPixel(x, y).a == 0)
			{
			    etat = 3;
			    return false;
			}
			if(event.type == sf::Event::MouseButtonPressed)
			{
		    		etat = 1;
		    		if((config/Action::SOURIS_CLIQUE)%2 == 1)
		    		{
		        		if(classe != NULL && funct != NULL) (classe->*(funct))(*this);
		        			return true;
		    		}
		    		return false;
			}
			else
			{
		    		etat = 2;
		    		if((config/Action::SOURIS_DECLIC)%2 == 1)
		    		{
		        		if(classe != NULL && funct != NULL) (classe->*(funct))(*this);
		        		return true;
		    		}
		    		return false;
			}
	    	}
		if(event.type == sf::Event::MouseMoved)
		{
			int x = event.mouseMove.x - sprite[image].getPosition().x;
			int y = event.mouseMove.y - sprite[image].getPosition().y;
			if(x < 0 || x >= sprite[image].getLocalBounds().width || y < 0 || y >= sprite[image].getLocalBounds().height)
			{
		    		etat = 3;
		    		return false;
			}
			Image * test(sprite[image].getImage());
			if(test->getImage() == NULL)
			{
				test->textureToImage();
			}	
			if(test->getImage()->getPixel(x, y).a == 0)
			{
		    		etat = 3;
				return false;
			}
			if(etat != 1)
		    		etat = 2;
			if((config/Action::SOURIS_DESSUS)%2 == 1)
		    		if(classe != NULL && funct != NULL) (classe->*(funct))(*this);
				return true;
	    	}
		return false;
	}

	template<typename CLASSE>
	const sf::Event & Bouton<CLASSE>:: getEvent()
	{
	    return event;
	}

	template<typename CLASSE>
	void Bouton<CLASSE>::setActive(bool active)
	{
	    if(active && etat == 0)
		etat = 3;
	    else if(!active)
		etat = 0;
	}

	template<typename CLASSE>
	bool Bouton<CLASSE>::isActive()
	{
	    return etat;
	}

	template<typename CLASSE>
	void Bouton<CLASSE>::setPositionR(const int x, const int y, int pour)
	{
		int i(0);
		while(i <= 4)
		{
			if(pour%2 == 0)
			{
				positionRX[i] = x;
				positionRY[i] = y;
				sprite[i].setPosition(positionX + x, positionY + y);
			}
			pour /= 2;
			++i;
		}
	}

	template<typename CLASSE>
	int Bouton<CLASSE>::getPositionRX(int pour)
	{
		int i(0);
		while(pour%2 == 0)
		{
			pour /= 2;
			++i;
		}
		return positionRX[i];
	}
	template<typename CLASSE>
	int Bouton<CLASSE>::getPositionRY(int pour)
	{
				int i(0);
		while(pour%2 == 0)
		{
			pour /= 2;
			++i;
		}
		return positionRY[i];
	}

	template<typename CLASSE>
	void Bouton<CLASSE>::setPosition(int positionX, int positionY)
	{
		int i(0);
		while(i <= 4)
		{
			this->positionX = positionX;
			this->positionY = positionY;
			sprite[i].setPosition(positionRX[i] + positionX, positionRY[i]+ positionY);
			++i;
		}
	}

	template<typename CLASSE>
	int Bouton<CLASSE>::getPositionX()
	{
		return positionX;
	}

	template<typename CLASSE>
	int Bouton<CLASSE>::getPositionY()
	{
		return positionY;
	}
}
#endif // BOUTON_H
