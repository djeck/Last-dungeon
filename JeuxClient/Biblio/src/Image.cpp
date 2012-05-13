#include "../include/Image.h"

namespace LD
{
	sf::Texture * Image::newTexture(sf::Texture & texture)
	{
		if(this->texture != NULL)
		{
			std::cerr << "Erreur : il existe déjà une texture!!" << std::endl;
			return NULL;
		}
		this->texture = new sf::Texture(texture);
		return this->texture;
	}

	sf::Texture * Image::newTexture()
	{
		if(texture != NULL)
		{
			std::cerr << "Erreur : il existe déjà une texture!!" << std::endl;
			return NULL;
		}
		texture = new sf::Texture();
		return texture;
	}

	void Image::deleteTexture()
	{
		if(texture == NULL)
			return;
		delete texture;
		texture = NULL;
	}

	sf::Texture * Image::getTexture() const
	{
		return texture;
	}

	sf::Image * Image::newImage()
	{
		if(image != NULL)
		{
			std::cerr << "Erreur : il existe déjà une image!!" << std::endl;
			return NULL;
		}
		image = new sf::Image();
		return image;			
	}

	sf::Image * Image::newImage(sf::Image & image)
	{
		if(this->image != NULL)
		{
			std::cerr << "Erreur : il existe déjà une image!!" << std::endl;
			return NULL;
		}
		this->image = new sf::Image(image);
		return this->image;			
	}

	sf::Image * Image::getImage()
	{
		return image;
	}

	void Image::deleteImage()
	{
		if(image == NULL)
			return;
		delete image;
		image = NULL;
	}

	sf::Image * Image::textureToImage()
	{
		if(image != NULL)
			deleteImage();
		image = new sf::Image(texture->copyToImage());
		return image;
	}

	sf::Texture * Image::imageToTexture(const sf::IntRect &area)
	{
		if(texture != NULL)
			deleteTexture();
		texture = new sf::Texture();
		texture->loadFromImage(*image, area);
		return texture;
	}

	Image::~Image()
	{
		if(texture != NULL)
			delete texture;
		if(image != NULL)
			delete image;
	}

	Image::Image(const Image &image){}
}
