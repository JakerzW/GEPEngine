#include "Collision.h"
#include "Core.h"
#include "GameObject.h"
#include "Transform.h"

#include <vector>

namespace engine
{
	void Collision::onUpdate()
	{
		checkCollisions();
	}

	Collision::Collision()
	{
		exists = true;
	}

	void Collision::setSize(glm::vec3 newSize)
	{
		size = newSize;
	}

	glm::vec3 Collision::getSize()
	{
		return size;
	}

	void Collision::checkCollisions()
	{
		currentPos = getTransform()->getValue("Position");

		//std::vector<std::shared_ptr<GameObject>> gameObjects = getCore()->getGameObjects();
		for (size_t i = 0; i < getCore()->getGameObjects().size(); i++)
		{
			if (getCore()->getGameObjects().at(i)->getComponent<Collision>() && getCore()->getGameObjects().at(i) != getGameObject())
			{
				glm::vec3 otherPos = getCore()->getGameObjects().at(i)->getComponent<Transform>()->getValue("Position");
				glm::vec3 otherSize = getCore()->getGameObjects().at(i)->getComponent<Collision>()->getSize();

				glm::vec3 thisMin = currentPos - size;
				glm::vec3 thisMax = currentPos + size;
				glm::vec3 otherMin = otherPos - otherSize;
				glm::vec3 otherMax = otherPos + otherSize;

				if ((thisMax.x >= otherMin.x || otherMax.x >= thisMin.x) && (thisMax.y >= otherMin.y || otherMax.y >= thisMin.y) && (thisMax.z >= otherMin.z || otherMax.z >= thisMin.z))
				{
					hasCollided = true;
					collisionObject = getCore()->getGameObjects().at(i);
				}

				break;
			}
		}
	}

	bool Collision::getHasCollided()
	{
		return hasCollided;
	}

	std::shared_ptr<GameObject> Collision::getCollisionObject()
	{
		return collisionObject;
	}
	bool Collision::getExists()
	{
		return exists;
	}
}
