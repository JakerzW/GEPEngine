#include "LaserObject.h"
#include "PlayerObject.h"

LaserObject::LaserObject(std::shared_ptr<engine::Core> corePtr)
{
	std::shared_ptr<engine::GameObject> self = corePtr->addGameObject();
	std::shared_ptr<engine::Renderer> rend = self->addComponent<engine::Renderer>();
	tf = self->addComponent<engine::Transform>();

	rend->setObjPath("../resources/models/laser.obj");
	rend->setTexPath("../resources/textures/laser.png");

	//tf->setValue("Position", playerTf->getValue("Position"));	
}

void LaserObject::setStart(glm::vec3 position)
{
	tf->setValue("Position", position); //Get player's transform
	tf->setMovement(speed, glm::vec3(0.0f, 1.0f, 0.0f));
}
