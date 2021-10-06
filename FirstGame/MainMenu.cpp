#include "MainMenu.h"

MenuResult MainMenu::Show(sf::RenderWindow& window) 
{

	sf::Texture texture;
	if (!texture.loadFromFile("images/MainMenu.png")) 
	{
		std::cout << "Couldnt find file";
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	MenuItem playButton;
	playButton.rect.top = 200;
	playButton.rect.left = 0;
	playButton.rect.height = 199;
	playButton.rect.width = 1024;
	playButton.action = MenuResult::Play;
	
	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1024;
	exitButton.rect.top = 400;
	exitButton.rect.height = 200;
	exitButton.action = MenuResult::Exit;

	MenuItems.push_back(playButton);
	MenuItems.push_back(exitButton);
	window.draw(sprite);
	window.display();

	return GetMenuResponse(window);
}

MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;
	for (it = MenuItems.begin(); it != MenuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.contains(sf::Vector2i(x, y)))
		{
			return (*it).action;
		}
	}
	return MenuResult::Nothing;
}

MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	while (42 != 43)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return MenuResult::Exit;
			}
		}
	}
}
