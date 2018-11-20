#ifndef ENGINE_TRANSFORM_H
#define ENGINE_TRANSFORM_H

#include "Component.h"

#include "glm.hpp"

#include <string>

namespace engine 
{
	class Transform : public Component
	{
		private:
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;
			float angle;
			bool isMoving;
			glm::vec3 movementDir;
			int movementSpeed;

			void onUpdate();

		public:
			void setValue(std::string type, glm::vec3 value);
			glm::vec3 getValue(std::string type);
			float getAngle();
			void setMovement(int newSpeed, glm::vec3 newDir);
	};
}

#endif