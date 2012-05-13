#include "../include/Fenetre.h"
namespace LD
{
	Fenetre * Fenetre::getId()
	{
		return this;
	}

	bool Fenetre::isRaccourcitClavier()
	{
		return raccourcitClavier;
	}

	bool Fenetre::isAutreDesactive()
	{
		return autreDesactive;
	}

	bool Fenetre::isNotTouch(int x, int y)
	{
		return false;
	}

	const Sprite Fenetre::getSprite()
	{
		Sprite sprite;
		return sprite;
	}
}
