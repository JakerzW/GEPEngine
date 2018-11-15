#include "Player.h"
#include "Input.h"
#include "Transform.h"
#include "Context.h"

namespace engine
{
	void Player::move()
	{
		//Take input and apply to transform
		glm::vec3 newPosition = getTransform()->getValue("Position");

		if (getInput()->getKeyDown("W"))
		{
			newPosition.y += speed * getContext()->getDeltaTime();
		}
		if (getInput()->getKeyDown("A"))
		{
			newPosition.x -= speed * getContext()->getDeltaTime();
		}
		if (getInput()->getKeyDown("S"))
		{
			newPosition.y -= speed * getContext()->getDeltaTime();
		}
		if (getInput()->getKeyDown("D"))
		{
			newPosition.x += speed * getContext()->getDeltaTime();
		}
		if (getInput()->getKeyDown("Q"))
		{
			newPosition.z -= speed * getContext()->getDeltaTime();
		}
		if (getInput()->getKeyDown("E"))
		{
			newPosition.z += speed * getContext()->getDeltaTime();
		}

		getTransform()->setValue("Position", newPosition);
	}

	void Player::onBegin()
	{
		speed = 100;
	}

	void Player::onUpdate()
	{
		move();
	}

	void Player::setSpeed(int newSpeed)
	{
		speed = newSpeed;
	}
}
