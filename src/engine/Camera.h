#ifndef ENGINE_CAMERA_H
#define ENGINE_CAMERA_H

#include <ext.hpp>

#include <memory>

namespace engine
{
	class Core;

	class Camera
	{
		friend class Core;

		private:
			glm::mat4 projMatrix;
			glm::mat4 viewMatrix;
			glm::vec3 position;
			glm::vec3 rotation;
			std::weak_ptr<Core> core;

		public:
			std::shared_ptr<Core> getCore();
			void onInit();
			void onInit(float fov, glm::mat4 firstViewMatrix, glm::vec3 firstPos, glm::vec3 firstRot);
			glm::mat4 getProjMatrix();
			void setProjMatrix(float fov);
			glm::mat4 getViewMatrix();
			void setViewMatrix(glm::mat4 newViewMatrix);
			glm::vec3 getPosition();
			void setPosition(glm::vec3 newRot);
			glm::vec3 getRotation();
			void setRotation(glm::vec3 newRot);
	};

}

#endif