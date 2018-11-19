#include "Transform.h"
#include "Camera.h"
#include "Context.h"

namespace engine
{
	void Transform::onUpdate()
	{
		if (isMoving)
		{
			position.x += (movementDir.x * movementSpeed * getContext()->getDeltaTime());
			position.y += (movementDir.y * movementSpeed * getContext()->getDeltaTime());
			position.z += (movementDir.z * movementSpeed * getContext()->getDeltaTime());
		}
	}

	void Transform::setValue(std::string type, glm::vec3 value)
	{
		if (type == "Position")
		{
			position = value;
		}
		else if (type == "Rotation")
		{
			rotation = value;
		}
		else if (type == "Scale")
		{
			scale = value;
		}
	}

	//Change to template and add angle
	glm::vec3 Transform::getValue(std::string type)
	{
		if (type == "Position")
		{
			return position;
		}
		else if (type == "Rotation")
		{
			return rotation;
		}
		else if (type == "Scale")
		{
			return scale;
		}
	}

	float Transform::getAngle()
	{
		return angle;
	}

	void Transform::setMovement(int newSpeed, glm::vec3 newDir)
	{
		movementSpeed = newSpeed;
		movementDir = newDir;
		isMoving = true;
	}
}