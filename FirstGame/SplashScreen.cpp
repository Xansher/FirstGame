#include "SplashScreen.h"

void SplashScreen::Show(sf::RenderWindow& window)
{
	/*sf::Image image;
	
	if (!image.loadFromFile("background.png") ) {
		std::cout << "chujni1";
		return;
	}*/

	
	sf::Texture texture;
	
	if (!texture.loadFromFile("images/New.png")) {
		std::cout << "chujnix";
		return;
	}
	
	//texture.loadFromImage(image);

	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	window.draw(sprite);
	window.display();

	sf::Event event;
	while (true) 
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed
				|| event.type == sf::Event::EventType::MouseButtonPressed
				|| event.type == sf::Event::EventType::Closed)
			{
				return;
			}
		}
	}

}