#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
	clock.restart();
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(GameObjects.begin(), GameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
	GameObjects.insert(std::pair<std::string, VisibleGameObject*>(name, gameObject));
}

void GameObjectManager::Remove(std::string name)
{
	std::map<std::string, VisibleGameObject*>::iterator results = GameObjects.find(name);
	if (results != GameObjects.end())
	{
		delete results->second;
		GameObjects.erase(results);
	}
}
int GameObjectManager::GetObjectCount() const
{
	return GameObjects.size();
}
VisibleGameObject* GameObjectManager::Get(std::string name) const
{
	std::map<std::string, VisibleGameObject*>::const_iterator results = GameObjects.find(name);
	if (results == GameObjects.end())
	{
		return NULL;
	}

	return results->second; 
	
}

void GameObjectManager::DrawAll(sf::RenderWindow& window)
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = GameObjects.begin();
	
	while (itr != GameObjects.end())
	{
		itr->second->Draw(window);
		itr++;
	}
}

void GameObjectManager::UpdateAll() 
{
	std::map<std::string, VisibleGameObject*>::const_iterator itr = GameObjects.begin();
	sf::Time elapsed;
	elapsed = clock.restart();
	float timeDelta = elapsed.asSeconds();
	while (itr != GameObjects.end())
	{
		itr->second->Update(timeDelta);
		itr++;
	}
}