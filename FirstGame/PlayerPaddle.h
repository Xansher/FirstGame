#pragma once
#include "VisibleGameObject.h"

class PlayerPaddle : public VisibleGameObject
{
public:
	PlayerPaddle();
	~PlayerPaddle();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow& window);

	float GetVelocity() const;

private:
	float velocity;
	float maxVelocity;
};
