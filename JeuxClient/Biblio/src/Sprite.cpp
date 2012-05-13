#include "../include/Sprite.h"

namespace LD
{
        Sprite::Sprite(Image& image) :
	image (NULL),
	m_textureRect(0, 0, 0, 0)
	{
	    setImage(image);
	}

        Sprite::Sprite(Image& image, const sf::IntRect& rectangle) :
	image (NULL),
	m_textureRect(0, 0, 0, 0)
	{
	    setImage(image);
	    setImageRect(rectangle);
	}

        void Sprite::setImage(Image& image, bool resetRect)
	{
	    // Recompute the texture area if requested, or if there was no valid texture before
	    if (resetRect || !this->image)
		setImageRect(sf::IntRect(0, 0, image.getTexture()->getSize().x, image.getTexture()->getSize().y));

	    // Assign the new texture
	    this->image = &image;
	}

	void Sprite::setImageRect(const sf::IntRect& rectangle)
	{
	    if (rectangle != m_textureRect)
	    {
		m_textureRect = rectangle;
		updatePositions();
		updateTexCoords();
	    }
	}

	void Sprite::setColor(const sf::Color& color)
	{
	    // Update the vertices' color
	    m_vertices[0].color = color;
	    m_vertices[1].color = color;
	    m_vertices[2].color = color;
	    m_vertices[3].color = color;
	}

        Image* Sprite::getImage()
	{
	    return image;
	}

	const sf::IntRect& Sprite::getImageRect() const
	{
	    return m_textureRect;
	}

	const sf::Color& Sprite::getColor() const
	{
	    return m_vertices[0].color;
	}

	sf::FloatRect Sprite::getLocalBounds() const
	{
	    float width = static_cast<float>(m_textureRect.width);
	    float height = static_cast<float>(m_textureRect.height);

	    return sf::FloatRect(0.f, 0.f, width, height);
	}

	sf::FloatRect Sprite::getGlobalBounds() const
	{
	    return getTransform().transformRect(getLocalBounds());
	}

	void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
	    if (image)
	    {
		states.transform *= getTransform();
		states.texture = image->getTexture();
		target.draw(m_vertices, 4, sf::Quads, states);
	    }
	}

	void Sprite::updatePositions()
	{
	    float width = static_cast<float>(m_textureRect.width);
	    float height = static_cast<float>(m_textureRect.height);

	    m_vertices[0].position = sf::Vector2f(0, 0);
	    m_vertices[1].position = sf::Vector2f(0, height);
	    m_vertices[2].position = sf::Vector2f(width, height);
	    m_vertices[3].position = sf::Vector2f(width, 0);
	}

	void Sprite::updateTexCoords()
	{
	    float left = static_cast<float>(m_textureRect.left);
	    float right = left + m_textureRect.width;
	    float top = static_cast<float>(m_textureRect.top);
	    float bottom = top + m_textureRect.height;

	    m_vertices[0].texCoords = sf::Vector2f(left, top);
	    m_vertices[1].texCoords = sf::Vector2f(left, bottom);
	    m_vertices[2].texCoords = sf::Vector2f(right, bottom);
	    m_vertices[3].texCoords = sf::Vector2f(right, top);
	}

	void Sprite::setImageVide()
	{
		image = NULL;
		m_textureRect = sf::IntRect(0, 0, 0, 0);
	}
}
