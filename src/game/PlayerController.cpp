#include "PlayerController.h"
#include "LaserObject.h"

void PlayerController::onUpdate()
{	
	move();

 	if (getInput()->getKeyDown("Space") && !shotMade)
	{
		shoot(getCore());
		shotMade = true;
	}
	if (getInput()->getKeyUp("Space") && shotMade)
	{
		shotMade = false;
	}	
}

void PlayerController::shoot(std::shared_ptr<engine::Core> corePtr)
{	
	std::shared_ptr<LaserObject> newLaser = std::make_shared<LaserObject>(corePtr);
}

bool PlayerController::getShotMade()
{
	return shotMade;
}
