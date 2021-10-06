#pragma once
#include "stdafx.h"
#include "SplashScreen.h"
#include "MainMenu.h"
#include "PlayerPaddle.h"
#include "GameObjectManager.h"
#include "GameBall.h"

enum class GameState {
	Uninitialized, ShowingSplash, Paused,
	ShowingMenu, Playing, Exiting
};


class Game 
{
public:
	Game();
	void Start();
	const sf::RenderWindow& GetWindow();
	const sf::Event& GetInput();
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;
	GameObjectManager& GetGameObjectManager();
private:
	bool IsExiting();
	void GameLoop();
	void ShowSplashScreen();
	void ShowMenu();
	GameState gameState;
	sf::RenderWindow mainWindow;
	
	GameObjectManager gameObjectMaganer;

};
extern Game g_Game;