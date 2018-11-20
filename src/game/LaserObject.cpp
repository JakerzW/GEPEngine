#include "LaserObject.h"

LaserObject::LaserObject(std::shared_ptr<engine::Core> corePtr)
{
	std::shared_ptr<engine::GameObject> self = corePtr->addGameObject();
	std::shared_ptr<engine::Renderer> rend = self->addComponent<engine::Renderer>();
	std::shared_ptr<engine::Transform> tf = self->addComponent<engine::Transform>();

	rend->setObjPath("../resources/models/laser.obj");
	rend->setTexPath("../resources/textures/laser.png");

	tf->setValue("Position", glm::vec3(0.0f, -3.0f, -20.0f)); //Get player's transform
	tf->setMovement(speed, glm::vec3(0.0f, 1.0f, 0.0f));
}