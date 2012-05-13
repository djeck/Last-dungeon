#include "../include/ListeImage.h"


namespace LD
{
	Image * ListeImage::setImage(Image & image, const std::string & nom)
	{
		std::string Nom = nom;
		if(nom == "")
			Nom = image.nom;
		if(existImage(Nom))
		{
			std::cerr << "Erreur ! Image déjà présente" << std::endl;
			return Liste[Nom];
		}
		Image * img = new Image(Nom);
		Liste[Nom] = img;
		if(image.getTexture() != NULL)
			img->newTexture(*image.getTexture());
		if(image.getImage() != NULL)
			img->newImage(*image.getImage());
		return img;
	}

	ListeImage::~ListeImage()
	{
	}

	void ListeImage::activer(bool active)
	{
		jeux->setActive(active);
	}

	Image * ListeImage::newImage(const std::string & nom)
	{
		if(existImage(nom))
		{
			std::cerr << "Erreur ! Image déjà présente" << std::endl;
			return Liste[nom];
		}
		Image * image = new Image(nom);
		Liste[nom] = image;
		return image;
	}
	Image * ListeImage::getImage(const std::string & nom)
	{
		if(!existImage(nom))
		{
			std::cerr << "Image inexistante" << std::endl;
			return NULL;
		}
		return Liste[nom];
	}
	bool ListeImage::deleteImage(const std::string &nom)
	{
		if(!existImage(nom))
		{
			std::cerr << "Image inexistante" << std::endl;
			return false;
		}
		delete Liste[nom];
		return true;
	}
	bool ListeImage::existImage(const std::string &nom)
	{
		return Liste.count(nom);
	}
}
