#include "VisibleGameObject.h"

VisibleGameObject::VisibleGameObject() 
{
	isLoaded = false;
}

VisibleGameObject::~VisibleGameObject() 
{

}

void VisibleGameObject::Load(std::string fileName)
{
	if (!Texture.loadFromFile(fileName))
	{
		FileName = "";
		isLoaded = false;
	}
	else
	{
		FileName = fileName;
		Sprite.setTexture(Texture);
		isLoaded = true;
	}
}
void VisibleGameObject::Update(float elapsedTime)
{

}
void VisibleGameObject::Draw(sf::RenderWindow& window)
{
	if (isLoaded)
	{
		window.draw(Sprite);
		
	}
}

void VisibleGameObject::SetPosition(float x, float y) 
{
	if (isLoaded)
	{
		Sprite.setPosition(x, y);
	}
}

bool VisibleGameObject::IsLoaded() const
{
	return isLoaded;
}
sf::Sprite& VisibleGameObject::GetSprite() 
{
	return Sprite;
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
	if (isLoaded)
	{
		return Sprite.getPosition();
	}
	return sf::Vector2f();
}

float VisibleGameObject::GetWidth() const 
{
	return Sprite.getTextureRect().width;
}
float VisibleGameObject::GetHeight() const 
{
	return Sprite.getTextureRect().height;
}

sf::Rect<float> VisibleGameObject::GetBoundingRect() const
{
	return Sprite.getGlobalBounds();

	/*
	sf::Vector2f size = Sprite.getOrigin();
	sf::Vector2f position = Sprite.getPosition();
	return sf::Rect<float>(
		position.x - size.x / 2,
		position.y - size.y / 2,
		position.x + size.x / 2,
		position.y + size.y / 2
		);*/
}