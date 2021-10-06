#include "GameBall.h"
#include "Game.h"
#include "stdafx.h"


GameBall::GameBall() {
	Load("images/ball.png");
	GetSprite().setOrigin(15, 15);
	GetSprite().setPosition(1024/2, 768/2);
	_velocity = 300.0f;
	std::srand(std::time(nullptr));
	//_angle = std::rand()%360;
	_angle = 60.0f;
}
GameBall::~GameBall() 
{
	
}

void GameBall::Update(float elapsedTime)
{
	_elapsedTimeSinceStart += elapsedTime;
	// Delay game from starting until 3 seconds have passed
	if (_elapsedTimeSinceStart < 3.0f)
		return;
	float moveAmount = _velocity * elapsedTime;

	

	float moveByX = LinearVelocityX(_angle) * moveAmount;
	float moveByY = LinearVelocityY(_angle) * moveAmount;


	if (GetPosition().x + moveByX <= 0 + GetWidth() / 2
		|| GetPosition().x + GetHeight() / 2 + moveByX >= 1024)
	{
		//Ricochet!
		_angle = 360.0f - _angle;
		if (_angle > 260.0f && _angle < 280.0f) _angle += 20.0f;
		if (_angle > 80.0f && _angle < 100.0f) _angle += 20.0f;
		moveByX = -moveByX;
	}
	if (GetPosition().y + moveByY <= 0 + GetHeight() / 2)
	{
		// move to middle of the screen for now and randomize angle
		//GetSprite().setPosition(Game::SCREEN_WIDTH / 2, Game::SCREEN_HEIGHT / 2);
		_angle = _angle - 90.0f;
		//_angle = _angle + 90.0f;


		moveByY = -moveByY;

		std::cout << "position:" << GetPosition().x << ", " << GetPosition().y << std::endl;
		std::cout << moveByY << std::endl;
	}
	
	PlayerPaddle* player1 = (PlayerPaddle * )g_Game.GetGameObjectManager().Get("Paddle1");
	if (player1) {
		if (GetPosition().y + moveByY <= 0 + GetHeight() / 2)
		{
			// move to middle of the screen for now and randomize angle
			//GetSprite().setPosition(Game::SCREEN_WIDTH / 2, Game::SCREEN_HEIGHT / 2);
			_angle = _angle - 90.0f;
			//_angle = _angle + 90.0f;


			moveByY = -moveByY;

			std::cout << "position:" << GetPosition().x << ", " << GetPosition().y << std::endl;
			std::cout << moveByY << std::endl;
		}

		sf::Rect<float> p1BB = player1->GetBoundingRect();

		
		if (p1BB.intersects(GetBoundingRect()))
		{
			std::cout << "taa" << std::endl;
			_angle = 360.0f - (_angle - 180.0f);
			if (_angle > 360.0f) _angle -= 360.0f;


			moveByY = -moveByY;
		}
	}
	
	GetSprite().move(moveByX, moveByY);
}

float GameBall::LinearVelocityX(float angle)
{
	angle -= 90;
	if (angle < 0) angle = 360 + angle;
	return (float)std::cos(angle * (3.1415926 / 180.0f));
}
float GameBall::LinearVelocityY(float angle)
{
	angle -= 90;
	if (angle < 0) angle = 360 + angle;
	return (float)std::sin(angle * (3.1415926 / 180.0f));
}