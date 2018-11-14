#include "Camera.h"
#include "Core.h"
#include "Screen.h"

namespace engine
{
	std::shared_ptr<Core> Camera::getCore()
	{
		return core.lock();
	}

	void Camera::onInit()
	{
		setProjMatrix(45.0f);
		setViewMatrix(glm::mat4(1.0f));
		setPosition(glm::vec3(0, 0, 0));
		setRotation(glm::vec3(0, 0, 0));
		//Set shader perspective
	}

	void Camera::onInit(float fov, glm::mat4 firstViewMatrix, glm::vec3 firstPos, glm::vec3 firstRot)
	{
		setProjMatrix(fov);
		setViewMatrix(firstViewMatrix);
		setPosition(firstPos);
		setRotation(firstRot);
	}


	glm::mat4 engine::Camera::getProjMatrix()
	{
		return projMatrix;
	}

	void engine::Camera::setProjMatrix(float fov)
	{
		projMatrix = glm::perspective(glm::radians(fov), getCore()->getScreen()->getRatio(), 0.1f, 100.0f);
	}

	glm::mat4 Camera::getViewMatrix()
	{
		return viewMatrix;
	}

	void Camera::setViewMatrix(glm::mat4 newViewMatrix)
	{
		viewMatrix = newViewMatrix;
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
