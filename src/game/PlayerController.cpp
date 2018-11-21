#include "PlayerController.h"
#include "LaserObject.h"

void PlayerController::onUpdate()
{	
	//move();

	glm::vec3 newPosition = getTransform()->getValue("Position");

	if (getInput()->getKeyDown("W"))
	{
		if (newPosition.y < -2.0f)
		{
			newPosition.y += speed * getContext()->getDeltaTime();
		}
	}
	if (getInput()->getKeyDown("A"))
	{
		if (newPosition.x > -7.1f)
		{
			newPosition.x -= speed * getContext()->getDeltaTime();
		}		
	}
	if (getInput()->getKeyDown("S"))
	{
		if (newPosition.y > -6.8f)
		{
			newPosition.y -= speed * getContext()->getDeltaTime();
		}
	}
	if (getInput()->getKeyDown("D"))
	{
		if (newPosition.x < 7.1f)
		{
			newPosition.x += speed * getContext()->getDeltaTime();
		}
	}
 	if (getInput()->getKeyDown("Space") && !shotMade)
	{
		shoot(getCore());
		shotMade = true;
	}
	if (getInput()->getKeyUp("Space") && shotMade)
	{
		shotMade = false;
	}	

	getTransform()->setValue("Position", newPosition);
}

void PlayerController::shoot(std::shared_ptr<engine::Core> corePtr)
{	
	std::shared_ptr<LaserObject> newLaser = std::make_shared<LaserObject>(corePtr);
	newLaser->setStart(getTransform()->getValue("Position"));	
}

bool PlayerController::getShotMade()
{
	return shotMade;
}
