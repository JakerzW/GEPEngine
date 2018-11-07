#include "Camera.h"

glm::mat4 engine::Camera::getProjMatrix()
{
	return projMatrix;
}

void engine::Camera::setProjMatrix(glm::mat4 newProjMatrix)
{
	projMatrix = newProjMatrix;
}
