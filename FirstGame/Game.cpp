#include "Game.h"

Game::Game() 
{
	gameState = GameState::Uninitialized;


}

void Game::Start()
{
	if (gameState != GameState::Uninitialized)
		return;

	mainWindow.create(sf::VideoMode(1024, 768, 32), "Pang!");
	
	PlayerPaddle* player1 = new PlayerPaddle();
	
	player1->SetPosition((1024 / 2) - 45, 700);
	gameObjectMaganer.Add("Paddle1", player1);

	GameBall* gameBall = new GameBall();
	gameObjectMaganer.Add("Ball", gameBall);
	

	gameState = GameState::ShowingSplash;

	while (!IsExiting())
	{
		GameLoop();
	}
	mainWindow.close();
	
}

const sf::RenderWindow& Game::GetWindow() 
{
	return mainWindow;
}

GameObjectManager& Game::GetGameObjectManager() 
{
	return gameObjectMaganer;
}

const sf::Event& Game::GetInput()
{
	sf::Event event;
	mainWindow.pollEvent(event);
		
	return event;
}

bool Game::IsExiting()
{
	if (gameState == GameState::Exiting)
		return true;
	else
		return false;
}

void Game::GameLoop()
{
	sf::Event currentEvent;
	mainWindow.pollEvent(currentEvent);

	switch (gameState)
	{
	case GameState::Uninitialized:
		break;
	case GameState::ShowingSplash:
	{
		ShowSplashScreen();
		break;
	}
			
	case GameState::Paused:
		break;
	case GameState::ShowingMenu:
	{
		ShowMenu();
		break;
	}
			
	case GameState::Playing:
	{
		
		mainWindow.clear(sf::Color(0, 0, 0));
		gameObjectMaganer.UpdateAll();
		gameObjectMaganer.DrawAll(mainWindow);
		mainWindow.display();


		if (currentEvent.type == sf::Event::Closed)
		{
			gameState = GameState::Exiting;
		}
		if (currentEvent.type == sf::Event::KeyPressed) 
		{
			if(currentEvent.key.code == sf::Keyboard::Escape)
			{
				ShowMenu();
			}
		}
		
			
	
		break;
	}
			
	case GameState::Exiting:
	{

		break;
	}
			
	default:
		break;
	}
	


}



void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(mainWindow);
	gameState = GameState::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MenuResult result=mainMenu.Show(mainWindow);
	switch (result)
	{
	case MenuResult::Exit:
	{
		gameState = GameState::Exiting;
		break;
	}
	case MenuResult::Play:
	{
		gameState = GameState::Playing;
		break;
	}
	}
}