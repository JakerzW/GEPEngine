#include <ext.hpp>

#include <memory>

namespace engine
{
	class Camera
	{
		private:
			glm::mat4 projMatrix;
			glm::vec3 position;
			glm::vec3 rotation;

		public:
			std::shared_ptr<Camera> init(glm::mat4 firstProjMatrix, glm::vec3 firstPos, glm::vec3 firstRot);
			glm::mat4 getProjMatrix();
			void setProjMatrix(glm::mat4 newProjMatrix);
			glm::vec3 getPosition();
			void setPosition(glm::vec3 newRot);
			glm::vec3 getRotation();
			void setRotation(glm::vec3 newRot);
	};

}