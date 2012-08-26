#ifndef Sprite_H
#define Sprite_H

#include <SFML/Graphics.hpp>
#include <cstddef>
#include "Image.h"

namespace LD
{
	/** @brief Sf::Sprite réécris pour avoir non plus un pointeur sur un sf::Texture mais un pointeur sur un sf::Image */
	class Sprite : public sf::Drawable, public sf::Transformable
	{
		public :
			/** @brief construit un sprite vide
				Rq : code exécutable dans le .cpp */
			Sprite() : image (NULL), m_textureRect(0, 0, 0, 0){};
			/** @brief constuit un sprite à partir d'une Image
				@param Image& image : Image sur lequel le sprite va se constuire */
                        explicit Sprite(Image& image);
			/** @brief constuit un sprite à partir d'une Image et n'affichera qu'un sous-rectangle de l'image
				@param Image& image : Image sur lequel le sprite va se constuire
				@param const sf::IntRect& rectangle : délimite le sous-rectangle de l'image qui sera sélectionné */
                        Sprite(Image& image, const sf::IntRect& rectangle);
			/** @brief change l'image du sprite 
				@param Image& image : nouvelle image
				@param bool resetRect : Booléen indiquant si on redimentionne le sprite avec les dimensions de la nouvelle image (true) ou non (false)*/
                        void setImage(Image& image, bool resetRect = false);
			/** @brief permet de sélectionner un sous rectangle de l'image du sprite
				@param const sf::IntRect& rectangle : délimite le sous-rectangle selectionné de l'image du sprite */
			void setImageRect(const sf::IntRect& rectangle);
			/** @brief permet de mettre pour le sprite une image monochromatique
				@param  const sf::Color& color : couleur a mettre au sprite */
			void setColor(const sf::Color& color);
			/** @brief permet de mettre une image vide dans le sprite */
			void setImageVide();
			/** @brief permet d'obtenir l'image du sprite
				@return Image* : image du sprite */
                        Image* getImage();
			/** @brief permet d'obtenir les limites du sprite
				return const sf::IntRect& : limite du sprite
			*/
			const sf::IntRect& getImageRect() const;
			/** @brief permet d'obtenir la couleur monochromatique du sprite */
			const sf::Color& getColor() const;
			/** @brief voir la documentation de sf::Sprite dans la SFML 2.0 */
			sf::FloatRect getLocalBounds() const;
			/** @brief voir la documentation de sf::Sprite dans la SFML 2.0 */
			sf::FloatRect getGlobalBounds() const;
		private :
			/** @brief permet de dessiner le sprite sur une cible
				voir la documentation de sf::Sprite dans la SFML 2.0  */
			virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
			/** @brief voir la documentation de sf::Sprite dans la SFML 2.0 */
			void updatePositions();
			/** @brief voir la documentation de sf::Sprite dans la SFML 2.0 */
			void updateTexCoords();
			// Member data
			/** @brief voir la documentation de sf::Sprite dans la SFML 2.0 */
			sf::Vertex         m_vertices[4]; 
			/** @brief Image du sprite */
                        Image* image;
			/** @brief limites du sprite */
			sf::IntRect        m_textureRect; 
	};
}

#endif // Sprite_H
