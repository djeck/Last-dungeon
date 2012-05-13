#ifndef Image_H
#define Image_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstddef>
#include <map>
#include <string>

namespace LD
{
	/** @brief Classe permettant de stocker des images en encapsulant une sf::Texture et une sf::Image en résolvant quelques bugs de la SFML 2.0 */
	class Image
	{
		public :
			/** @brief construit une image
				Rq : code exécutable dans le .cpp
				@param const std::string & nom : nom de l'image */
			Image(const std::string & nom) : nom(nom), texture(NULL), image(NULL){};
			/** @brief Inclus, par copie, une nouvelle sf::Texture à l'image et renvois un pointeur vers le sf::Texture inclus
				@param sf::Texture & texture : sf::Texture à copier et à mettre dans l'image
				@return sf::Texture * : pointeur vers la copie de la sf::Texture */
			sf::Texture * newTexture(sf::Texture & texture);
			/** @brief créé une nouvelle sf::Texture
				@return sf::Texture * : pointeur vers la sf::Texture créée
			*/
			sf::Texture *newTexture();
			/** @brief supprimer la sf::Texture de l'image */
			void deleteTexture();
			/** @brief retourne la sf::Texture de l'image
				@return sf::Texture : sf::Texture de l'image */
			sf::Texture * getTexture() const;
			/** @brief permet de créer une nouvelle sf::Image
				@return sf::Image * : pointeur vers la nouvelle sf::Image créée */
			sf::Image * newImage();
			/** @brief permet de créer une nouvelle sf::Image par copie
				@param sf::Image & image : sf::Image à copier
				@return sf::Image * : pointeur vers la nouvelle sf::Image créée */
			sf::Image * newImage(sf::Image & image);
			/** @brief retourne un pointeur vers la  sf::Image de l'image
				@return sf::Image * : pointeur vers la sf::Image de l'image */
			sf::Image * getImage();
			/** @brief supprimer la sf::Image de l'image */
			void deleteImage();
			/** @brief permet d'obtenir une sf::Image à partir de la sf::Texture déjà présente dans l'image
				@return sf::Image * : pointeur sur la sf::Image créée */
			sf::Image * textureToImage();
			/** @brief permet d'obtenir un sf::Texture à partir de la sf::Image déjà présente dans l'image
				@param const sf::IntRect &area=sf::IntRect() : si on souhaite que la sf::Texture ne contienne qu'un sous-rectangle de la sf::Image (par défaut, la sf::Texture contient toute l'image de la sf::Image
				@return sf::Texture * : pointeur vers la sf::Texture créée */
			sf::Texture * imageToTexture(const sf::IntRect &area=sf::IntRect());
			/** @brief Destructeur */
			~Image();
			/** @brief nom de l'image */
			const std::string nom;
		private :
			/** @brief interdit la construction par copie d'image
				Rq : je ne suis pas sûr que cela marche. Im faudra aussi faire de même avec une surchage de l'opérateur d'affectation */
			Image(const Image &image);			
			/** @brief pointeur sur la sf::Texture de l'image (NULL s'il n'y a pas de sf::Image) */
			sf::Texture * texture;
			/** @brief pointeur sur la sf::Image de l'image (NULL s'il n'y a pas de sf::Image) */
			sf::Image * image;	
	};
}

#endif // Image_H
