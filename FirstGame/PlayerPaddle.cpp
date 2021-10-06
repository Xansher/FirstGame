#include "PlayerPaddle.h"
#include "Game.h"

PlayerPaddle::PlayerPaddle(): velocity(0),maxVelocity(600.0f)
{
	Load("images/paddle.png");
	GetSprite().setOrigin(45,15);
	GetSprite().setPosition(1024 / 2, 768 / 2);
}

PlayerPaddle::~PlayerPaddle() 
{

}

void PlayerPaddle::Draw(sf::RenderWindow& window)
{
	VisibleGameObject::Draw(window);
}

float PlayerPaddle::GetVelocity() const
{
	return velocity;
}

void PlayerPaddle::Update(float elapsedTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velocity -= 3.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velocity += 3.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		velocity = 0.0f;
	}

	if (velocity > maxVelocity)
		velocity = maxVelocity;

	if (velocity < -maxVelocity)
		velocity = -maxVelocity;

	sf::Vector2f pos = this->GetPosition();

	if (pos.x  < GetSprite().getLocalBounds().width / 2
		|| pos.x >(1024 - GetSprite().getLocalBounds().width / 2))
	{
		velocity = -velocity; // Bounce by current velocity in opposite direction
	}

	GetSprite().move(velocity * elapsedTime, 0);
}