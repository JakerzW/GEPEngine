#include "Transform.h"
namespace engine
{
	void engine::Transform::setPosition(glm::vec3 pos)
	{
		position = pos;
	}

	void engine::Transform::setRotation(glm::vec3 rot)
	{
		rotation = rot;
	}

	void engine::Transform::setScale(glm::vec3 sca)
	{
		scale = sca;
	}

	glm::vec3 engine::Transform::getPosition()
	{
		return position;
	}

	glm::vec3 engine::Transform::getRotation()
	{
		return rotation;
	}

	glm::vec3 engine::Transform::getScale()
	{
		return scale;
	}
}