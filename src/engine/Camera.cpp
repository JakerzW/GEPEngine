#include "Camera.h"

namespace engine
{
	std::shared_ptr<Camera> Camera::init(glm::mat4 firstProjMatrix, glm::vec3 firstPos, glm::vec3 firstRot)
	{
		std::shared_ptr<Camera> rtn = std::make_shared<Camera>();
		rtn->setProjMatrix(firstProjMatrix);
		rtn->setPosition(firstPos);
		rtn->setRotation(firstRot);

		return rtn;
	}

	glm::mat4 engine::Camera::getProjMatrix()
	{
		return projMatrix;
	}

	void engine::Camera::setProjMatrix(glm::mat4 newProjMatrix)
	{
		projMatrix = newProjMatrix;
	}

	glm::vec3 engine::Camera::getPosition()
	{
		return position;
	}

	void engine::Camera::setPosition(glm::vec3 newPos)
	{
		position = newPos;
	}
	glm::vec3 Camera::getRotation()
	{
		return rotation;
	}
	void Camera::setRotation(glm::vec3 newRot)
	{
		rotation = newRot;
	}
}
