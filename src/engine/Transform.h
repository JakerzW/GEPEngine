#include "Component.h"
#include "glm.hpp"

namespace engine 
{
	class Transform : public Component
	{
		private:
			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;			

		public:
			void setPosition(glm::vec3 pos);
			void setRotation(glm::vec3 rot);
			void setScale(glm::vec3 sca);
			glm::vec3 getPosition();
			glm::vec3 getRotation();
			glm::vec3 getScale();
	};

}