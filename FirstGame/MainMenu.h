#pragma once
#include "stdafx.h"
enum class MenuResult {
	Nothing, Exit, Play
};
class MainMenu
{
public:

	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};

	MenuResult Show(sf::RenderWindow& window);
	
private:
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	std::list<MenuItem> MenuItems;
};