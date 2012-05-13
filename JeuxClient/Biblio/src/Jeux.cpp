#include "../include/Jeux.h"
#include <SFML/Graphics.hpp>
#include <cstddef>

namespace LD
{
	Jeux::Jeux(const std::string & titre, int tailleX, int tailleY, int imageParSec, int fenetreMax) :
				nb_fenetre(0),
				continu(true),
				tete(NULL),
				fond(NULL),
				Thread(&Jeux::afficher, this),
				NB_FEN_MAX(fenetreMax),
				IMG_PAR_SEC(imageParSec),
				wind(sf::VideoMode(tailleX, tailleY, 32), titre, sf::Style::Titlebar | sf::Style::Close)
	{
		if (!icone.loadFromFile("icone.png"))
		{
			std::cerr << "icone.png non trouv�e\n" << std::endl;
		}
		wind.setIcon(icone.getSize().x, icone.getSize().y, icone.getPixelsPtr());
		wind.clear();		
		wind.display();
	}

	Jeux::~Jeux()
	{
	}

	void Jeux::lancer()
	{
		wind.setActive(false);
		Thread.launch();
		event();
		Thread.wait();
	}

	void Jeux::event()
	{
		while (continu)
		{
			sf::Event Event;
			while (wind.waitEvent(Event))
			{
				if((Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Escape) || Event.type == sf::Event::Closed)
				{
					continu = false;
					break;
				}
				if(tete != NULL)
				{
					Fenetre *destinataire = tete;
					if(Event.type == sf::Event::MouseButtonPressed)
					{
						bool tour = false;
						while(destinataire->isNotTouch(Event.mouseButton.x, Event.mouseButton.y))//TODO coordonn�e
						{
							if(destinataire == tete && tour)
							{
								destinataire = fond;
								break;
							}
							if(destinataire->isAutreDesactive())
							{
							    destinataire = NULL;
							    break;
							}
							tour = true;
							destinataire = destinataire->maillon.precedante;
						}
					}
					if(destinataire != NULL && destinataire != fond)
					{
						if(destinataire != tete)
						{
					                destinataire->maillon.suivante->maillon.precedante = destinataire->maillon.precedante;
		        			        destinataire->maillon.precedante->maillon.suivante = destinataire->maillon.suivante;
		        			        tete->maillon.suivante->maillon.precedante = destinataire;
		        			        destinataire->maillon.precedante = tete;
		        			        destinataire->maillon.suivante = tete->maillon.suivante;
		        			        tete->maillon.suivante = destinataire;
		        			        tete = destinataire;
		        			}
						if(Event.type == sf::Event::KeyPressed && destinataire->isRaccourcitClavier())
						{
							std::cout << "raccourcit" << std::endl;//raccourcit clavier()
						}
		            			else
						{
							destinataire->setEvent(Event);
						}
					}
					else if(destinataire != NULL)
					{
						fond->setEvent(Event);
						destinataire = tete;
						bool tour = true;
		            			while(destinataire != tete || tour)
		            			{
							tour = false;
							destinataire->lost_focus();
							destinataire = destinataire->maillon.precedante;
						}
					}
				}
				else if(fond != NULL)
				{
				        fond->setEvent(Event);
				}
			}
		}
	}

	bool Jeux::newFenetre(Fenetre *id)
	{
		if(id == NULL)
		{
			return false;//TODO erreur
		}
		if(nb_fenetre == NB_FEN_MAX)
		{
			return false;//TODO erreur
		}
		if(tete == NULL)
		{
			id->maillon.suivante = id;
			id->maillon.precedante = id;
		}
		else
		{
			id->maillon.suivante = tete->maillon.suivante;//la derni�re fen�tre est la fenetre maillon.suivante de la nouvelle
			id->maillon.precedante = tete;//la t�te est la fenetre pr�c�dante de la nouvelle
			tete->maillon.suivante->maillon.precedante = id;//la nouvelle est la fen�tre pr�c�dante de la derni�re fenetre
			tete->maillon.suivante = id;//la nouvelle fen�tre est la fen�tre maillon.suivante de la t�te
		}
		tete = id;
		++nb_fenetre;
		return true;
	}

	bool Jeux::closeFenetre(Fenetre *id)
	{
		Fenetre *tmp = tete;
		if(tete == NULL)
		{
			return false; //TODO erreur pas de fen�tre
		}
		bool tour(false);
		while(id != tmp)
		{
			if(tmp == tete && tour)
			{
				return false;//TODO erreur pas trouv�
			}
			tour = true;
			tmp = tmp->maillon.precedante;
		}
		nb_fenetre--;
		if(tete == id)
		{
			if(nb_fenetre == 0)
			    	tete = NULL;
			else
			{
			    tete = id->maillon.precedante;
			    id->maillon.precedante->maillon.suivante = id->maillon.suivante;
			    id->maillon.suivante->maillon.precedante = id->maillon.precedante;
			}
		return true;
		}
		id->maillon.precedante->maillon.suivante = id->maillon.suivante;
		id->maillon.suivante->maillon.precedante = id->maillon.precedante;
		return true;
	}

	void Jeux::afficher()
	{
		wind.setActive(true);
		wind.setFramerateLimit(IMG_PAR_SEC);
		while(continu)
		{
			wind.clear();
			if(fond != NULL)
			{
				wind.draw(fond->getSprite());
			}
			if(tete != NULL){
				Fenetre *tmp = tete->maillon.suivante;
				Fenetre *tmp2 = tmp;
				bool tour = true;
				while(tmp != tmp2 || tour)
				{
					tour = false;
					wind.draw(tmp->getSprite());
					tmp = tmp->maillon.suivante;
				}
			}
			wind.display();
			wind.setActive(false);
			aff.unlock();
			aff.lock();
		}
	}

	void Jeux::setFond(Fenetre * new_fond)
	{
	    if(fond != NULL)
		delete fond;
	    fond = new_fond;
	}

	void Jeux::setActive(bool act)
	{
		if(act)
		{
			aff.lock();
			wind.setActive(true);
		}
		else
		{
			wind.setActive(false);
			aff.unlock();
		}
	}
}
