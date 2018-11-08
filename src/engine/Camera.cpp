#include "Camera.h"
#include "Core.h"

namespace engine
{
	void Camera::init()
	{
		setProjMatrix(glm::mat4(1.0f));
		//Set shader perspective
	}

	void Camera::init(glm::mat4 firstProjMatrix, glm::vec3 firstPos, glm::vec3 firstRot)
	{
		setProjMatrix(firstProjMatrix);
		setPosition(firstPos);
		setRotation(firstRot);
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
