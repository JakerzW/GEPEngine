#include "Transform.h"
#include "Camera.h"

namespace engine
{
	void Transform::onUpdate()
	{
		
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
}