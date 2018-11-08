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

			void onUpdate();

		public:
			void setValue(std::string type, glm::vec3 value);
			glm::vec3 getValue(std::string type);
	};
}