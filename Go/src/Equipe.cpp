#include "../includes/Equipe.h"

Equipe::Equipe(const int numero, std::string & nomEquipe, float komi) :
	numero(numero),
	nom(nomEquipe),
	komi(komi)
{
	

}

Equipe::~Equipe()
{
	//TODO
}

void Equipe::addJoueur(Joueur * joueur)
{
	listeJoueur.push_back(joueur);
}
