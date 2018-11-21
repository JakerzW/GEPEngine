#ifndef ENGINE_COLLISION_H
#define ENGINE_COLLISION_H

#include "Component.h"

#include "ext.hpp"

namespace engine
{
	class GameObject;

	class Collision : public Component
	{
		protected:
			glm::vec3 size;
			glm::vec3 currentPos;
			void onUpdate();
			bool hasCollided = false;
			std::shared_ptr<GameObject> collisionObject;
			bool exists;

		public:
			Collision();
			void setSize(glm::vec3 newSize);
			glm::vec3 getSize();
			void checkCollisions();
			bool getHasCollided();
			std::shared_ptr<GameObject> getCollisionObject();
			bool getExists();
	};
}

#endif