#include "GameCollider.h"
#include "engine/Core.h"
#include "engine/GameObject.h"
#include "engine/Transform.h"

#include <vector>

void GameCollider::onUpdate()
{
	checkCollisions();

	if (hasCollided)
	{
		std::string thisId = getId()->getThisId();
		std::string collisionObjectID = collisionObject->getComponent<engine::ID>()->getThisId();

		std::vector<std::shared_ptr<engine::GameObject>> gameObjects = getCore()->getGameObjects();

		if ((collisionObjectID == "Player" && thisId == "Asteroid") || (thisId == "Player" && collisionObjectID == "Asteroid"))
		{
			getCore()->stop();
		}

		if ((collisionObjectID == "Asteroid" && thisId == "Laser") || (collisionObjectID == "Laser" && thisId == "Asteroid"))
		{
			bool colDeleted = false;
			bool thisDeleted = false;

			for (size_t i = 0; i < gameObjects.size(); i++)
			{
				if (collisionObject == gameObjects.at(i))
				{
					getCore()->getGameObjects().erase(getCore()->getGameObjects().begin() + i);
					i--;
					colDeleted = true;
				}
				else if (getGameObject() == gameObjects.at(i))
				{
					getCore()->getGameObjects().erase(getCore()->getGameObjects().begin() + i);
					i--;
					thisDeleted = true;
				}
				if (colDeleted && thisDeleted)
				{
					break;
				}
			}			
		}
	}
}
