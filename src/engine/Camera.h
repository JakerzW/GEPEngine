#include "engine/Engine.h"

#include <ext.hpp>

#include <memory>

namespace engine
{
	class Camera
	{
		private:
			glm::mat4 projMatrix;

		public:
			glm::mat4 getProjMatrix();
			void setProjMatrix(glm::mat4 newProjMatrix);
	};

}