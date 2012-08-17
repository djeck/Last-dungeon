#include "../includes/Test.h"

#include <iostream>
#include <limits>
#include <cstdlib>

int main(void)
{
	Test test;
	char c;
	std::cout << "Voulez-vous lancer une nouvelle partie de Go? (O/N)" << std::endl;
	std::cin >> c;
	while(c == 'o' || c == 'O')
	{
		test.iniNewGo();
		test.commencerPartie();
		//
		std::cout << "Voulez-vous lancer une nouvelle partie de Go? (O/N)" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> c;
	}
	return 0;
}

void Test::iniNewGo()
{
	std::cout << "Veuillez entrer la taille du plateau de Go (x-y):" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> tailleX;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '-');
	std::cin >> tailleY;
	std::cout << "Veuillez entrer le temps maximum de jeux par joueur par tour (sans limite : 0) :" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> tmpMaxTour;
	std::cout << "Veuillez entrer le temps maximum de jeux (sans limite : 0) :" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> tmpMax;
	std::cout << "Veuillez entrer le nombre de tour maximum de jeux (sans limite : 0) :" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin >> tourMax;
	std::cout << "Veuillez entrer le nombre d'équipes :" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int nbEquipe;
	std::cin >> nbEquipe;
	for(int i(0);i != nbEquipe;++i)
		addEquipe(i);
}

void Test::addEquipe(int numEquipe)
{
	std::cout << "Initialisation de l'Equipe n°" << numEquipe << " :" << std::endl;
	std::cout << "Veuillez entrer le nom de l'équipe :" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string nomEquipe;
	std::cin >> nomEquipe;
	std::cout << "Veuillez entrer le komi pour l'équipe :" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	float komi;
	std::cin >> komi;
	Equipe * equipe(new Equipe(numEquipe, nomEquipe, komi));
	listeEquipe.push_back(equipe);
	std::cout << "Veuillez entrer le nombre de joueurs :" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int nbJoueurs;
	std::cin >> nbJoueurs;
	for(int i(0);i!=nbJoueurs;++i)
		equipe->addJoueur(addJoueur(i));
}

Test::Test()
{

}

Joueur * Test::addJoueur(int numJoueur)
{
	std::cout << "Veuillez entre l'handicap pour le joueur n°" << numJoueur << " :" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	int handicap;
	std::cin >> handicap;
	Joueur * joueur = new Joueur(handicap);
	return joueur;
}

Test::~Test()
{
	std::vector<Equipe *>::iterator p = listeEquipe.begin();
	std::vector<Equipe *>::iterator fin = listeEquipe.end();
	while(p != fin)
	{	//TODO
        	//delete *p;
                //p->clear();
		p++;
	}
}

void Test::commencerPartie(void)
{
	LD::Go go(listeEquipe, tailleX, tailleY, tmpMaxTour, tourMax, tmpMax);
	afficher(go);
	std::cout << "La partie commence !" << std::endl;
	//2 threads de temps
	//poser les handicap
	int i(0)
	while(i != tourMax)
	{
		tour(go);
		++i;
	}
	//fin partie
}

void Test::afficher(const LD::Go & go)
{
	system("clear");	
	std::vector<LD::Groupe *>::const_iterator p = go.afficher().begin();
	std::vector<LD::Groupe *>::const_iterator const fin = go.afficher().end();
	int i(0);
	while(p != fin)
	{
		if(*p == 0)
		{
			std::cout << " .";
		}
		else;
		//TODO affichage des pions des perso
		++p;
		++i;
		if(i == tailleX)
		{
			std::cout << std::endl;
			i = 0;
		}
	}
}

void Test::tour(const LD::Go & go)
{
	std::cout << "Joueur 0 : veuillez jouer (x-y) :" << std::endl;
	//go.jouer(j, x, y);
	int j(1);	
	while(j != 0)
	{
		std::cout << "Joueur " << " : veuillez jouer (x-y) :" << std::endl;
		//go.jouer(j, x, y);
		++j;
	}
	afficher(go);
}
