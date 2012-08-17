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
		@brief Namespace constenant les �v�nements pouvant d�clancer une action
		Rq : Supprimer le namespace et les inclures en tant qu'attribut static constant dans LD::Bouton
		@see LD::Bouton */
	namespace Action
	{
		/** @brief Aucun �v�nement
			@see LD::Bouton */
		const int AUCUN = 0;
		/** @brief �v�nement clavier
			@see LD::Bouton */
		const int CLAVIER = 1;
		/** @brief On a cliqu� sur le bouton
			@see LD::Bouton */
		const int SOURIS_CLIQUE = 2;
		/** @brief Le curseur est sur le bouton
			@see LD::Bouton */
		const int SOURIS_DESSUS = 4;
		/** @brief On a cliqu� sur le bouton puis on a relach� le clique, toujours sur le bouton
			@see LD::Bouton */
		const int SOURIS_DECLIC = 8;
		/** @brief Le curseur �tait sur le bouton mais n'y est plus
			@see LD::Bouton */
		const int SOURIS_PARTIE = 16;
	}
	/** @namespace Etat
		@brief namespace contenant tous les �tats possibles d'un bouton
		Rq : Supprimer le namespace et les inclures en tant qu'attribut static constant dans LD::Bouton
		@see LD::Bouton */
	namespace Etat
	{
		/** @brief Lorsque le bouton est d�sactiv�
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
	/** @brief Classe Bouton. Un bouton peut avoir 4 �tats et avoir une image pour chacun de ces �tats. Il peut aussi d�clencher une unique fonction suivant 5 �v�nements.

	Rq : Renommer cette classe NewBouton et cr�er une classe Bouton sans template dont h�ritera NewBouton ce qui permettra d'utiliser des pointeurs et des r�f�rences plus g�n�rales
	*/
	template<typename CLASSE>
	class Bouton
	{
		/** @brief Fonction est le type correspondant � un pointeur sur une m�thode de la classe CLASSE (template) */
	    typedef void (CLASSE::*Fonction)(Bouton &);
	    public:
		/** @brief Constructeur d'un bouton
			Rq : mettre sa d�finition � l'exterieur
			@param int etat : �tat initial du bouton
			Rq : cr�er 4 attributs static constants
			@param CLASSE * classe : classe � qui appartient la m�thode qu'il faudra appeler (par d�faut NULL).
			@param Fonction funct : pointeur sur la m�thode qu'il faudra appeler (par d�faut NULL)
			@param int config : D�termine les �v�nements qui d�clencherons l'appel de la m�thode. Par d�faut : LD::Action::Aucun Utilisation : OPTION1 | OPTION2. @see LD::Action
			
		*/
		Bouton(int etat = 0, CLASSE * classe = NULL, Fonction funct = NULL, int config = LD::Action:Aucun):
			etat(etat),
			funct(funct),
			classe(classe),
			config(config),
			positionX(0),
			positionY(0){};

		//attributs publics :
		/** @brief D�termine les �v�nements qui d�clencherons l'appel de la m�thode, mis en attribut public car il n'y a aucune v�rification � effectuer au niveau du setter. @see LD::Action
			
		*/
		int config;
		/** @brief Pointeur sur la m�thode qu'il faudra appeler, mis en attribut public car il n'y a aucune v�rification � effectuer au niveau du setter.

		*/
		Fonction funct;
		/** @brief Classe � qui appartient la m�thode qu'il faudra appeler, mis en attribut public car il n'y a aucune v�rification � effectuer au niveau du setter.
		*/
		CLASSE * classe;
		/** @brief �tat du bouton
			Rq : cr�er 4 attributs static constants :0 : d�sactive, 1 : onclick, 2 : onblur, 3 : normal; */
		int etat;
		/** @brief Permet d'associer une image � un ou plusieurs �tats du bouton
			@param LD::Image * const image : image � utiliser
			@param int pour : �tats pour lesquels il faudra utiliser l'image (par d�faut LD::Etat::Desactive) utilisation : Etat1 | Etat2
			@param int x : ajustement en pixel de l'image sur la largeur relativement � la position du bouton (par d�faut 0)
			@param int y : ajustement en pixel de l'image sur la hauteur relativement � la position du bouton (par d�faut 0)*/
                void setImage(Image * const image, int pour = Etat::Desactive, int x = 0, int y = 0);
		/** @brief M�thode permettant d'obtenir l'image du bouton pour ensuite l'afficher
			@return const LD::Sprite & : image du bouton � afficher
		*/
		const Sprite &getImage(void);
		/** @brief Permet de modifier l'ajustement en pixel de l'image relativement � la position du bouton @see setImage
			@param const int x : valeur de l'ajustement sur la largeur
			@param const int y : valeur de l'ajustement sur la hauteur
			@param int pour : �tat(s) sur le(s)quel(s) l'ajustement porte (par d�faut LD::Etat::Desactive) @see setImage
		*/
		void setPositionR(const int x, const int y, int pour = Etat::Desactive);
		/** @brief obtient la valeur de l'ajustement sur la largeur pour un �tat donn�
		Rq : fusionner avec la fonction @see getPositionRX et retourner une structure
		Rq2 : pour le pour utiliser les m�me valeurs que @see Etat;
			@param int pour : �tat pour lequel on veut connaitre l'ajustement sur la largeur
			@return int : ajustement sur la largeur */
		int getPositionRX(int pour = 1);
		/** @brief obtient la valeur de l'ajustement sur la hauteur pour un �tat donn�
		Rq : fusionner avec la fonction @see getPositionRY et retourner une structure
		Rq2 : pour le pour utiliser les m�me valeurs que @see Etat;
			@param int pour : �tat pour lequel on veut connaitre l'ajustement sur la hauteur
			@return int : ajustement sur la hauteur */
		int getPositionRY(int pour = 1);
		/** @brief M�thode permettant de modifier la position du bouton
			@param int positionX : nouvelle position sur la largeur du bouton
			@param int positionY : nouvelle position sur la hauteur du bouton */
		void setPosition(int positionX, int positionY);
		/** @brief M�thode permettant d'obtenir la position du bouton sur la largeur
			Rq : Fusionner avec @see getPositionY
			@return int : position sur la largeur du bouton
			@see getPositionY */
		int getPositionX(void);
		/** @brief M�thode permettant d'obtenir la position du bouton sur la hauteur
		Rq : Fusionner avec @see getPositionX
		@return int : position sur la hauteur du bouton
		@see getPositionX */
		int getPositionY(void);
		/** @brief m�thode virtuelle permettant de traiter l'�v�nement pass� en param�tre
			@param const sf::Event & event : �v�nement � traiter
			@return bool : setEvent retourne true si il est la cible de l'�v�nement, false sinon.
		*/
		virtual bool setEvent(const sf::Event & event); //traite l'�v�nement
		/** @brief m�thode permettant de r�cup�rer l'�v�nement trait� par le bouton
			@return const sf::Event & : �v�nement trait� par le bouton
		*/
		const sf::Event & getEvent();
		/** @brief M�thode retournant true si le bouton n'est pas d�sactiv�, false sinon.
			@return bool : true si  le bouton n'est pas d�sactiv�, false sinon. */
		bool isActive();
		/** @brief M�thode permettant d'activer/de d�sactiver le bouton
			@param bool active : true si on souhaite activer le bouton
			false si on souhaite le d�sactiver */
		void setActive(bool active);
	    protected:
		/** @brief Les quatres images pour les quatres �tats du bouton
		*/
		Sprite sprite[4];
		/** @brief �v�nement tait� */
		sf::Event event;
		/** @brief position sur la largeur du bouton.
			Rq : utiliser une structure et fusionner avec positionY */
		int positionX;
		/** @brief position sur la hauteur du bouton.
			Rq : utiliser une structure et fusionner avec positionX */		
		int positionY;
		/** @brief position relative sur la largeur des quatres images par rapport � celle du bouton.
			Rq : utiliser une structure et fusionner avec positionRY */
		int positionRY[4];
		/** @brief position relative sur la hauteur des quatres images par rapport � celle du bouton.
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
		std::cerr << "/!\\L'image Normale du bouton doit �tre renseign�e avant tout affichage!!!" << std::endl;
	    return sprite[3];
	}


	template<typename CLASSE>
	bool Bouton<CLASSE>:: setEvent(const sf::Event & event)
	{
		int image(etat);
		if(sprite[etat].getImage() == NULL)
			image = 3;
		this->event = event;
		if(etat == 0)//bouton d�sactiv�
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
