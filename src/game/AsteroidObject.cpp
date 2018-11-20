#include "AsteroidObject.h"

AsteroidObject::AsteroidObject(std::shared_ptr<engine::Core> corePtr)
{
	std::shared_ptr<engine::GameObject> self = corePtr->addGameObject();
	std::shared_ptr<engine::Renderer> rend = self->addComponent<engine::Renderer>();
	std::shared_ptr<engine::Transform> tf = self->addComponent<engine::Transform>();

	rend->setObjPath("../resources/models/asteroid.obj");
	rend->setTexPath("../resources/textures/asteroid.png");

	tf->setValue("Position", glm::vec3(0.0f, 0.0f, -20.0f));
	tf->setValue("Rotation", glm::vec3(0.0f, 1.0f, 0.0f));
	tf->setValue("Scale", glm::vec3(2.0f, 2.0f, 2.0f));
}