#include "Camera.h"
#include "Core.h"
#include "GameObject.h"

namespace engine
{
	void Camera::onInit()
	{
		setProjMatrix(glm::mat4(1.0f));
		setPosition(glm::vec3(0, 0, 0));
		setRotation(glm::vec3(0, 0, 0));
		//Set shader perspective
	}

	void Camera::onInit(glm::mat4 firstProjMatrix, glm::vec3 firstPos, glm::vec3 firstRot)
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
