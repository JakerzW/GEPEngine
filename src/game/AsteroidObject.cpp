#include "AsteroidObject.h"
#include "GameCollider.h"

AsteroidObject::AsteroidObject(std::shared_ptr<engine::Core> corePtr)
{
	std::shared_ptr<engine::GameObject> self = corePtr->addGameObject();
	std::shared_ptr<engine::Renderer> rend = self->addComponent<engine::Renderer>();
	tf = self->addComponent<engine::Transform>();
	std::shared_ptr<engine::ID> id = self->addComponent<engine::ID>();
	//std::shared_ptr<GameCollider> gc = self->addComponent<GameCollider>();

	rend->setObjPath("../resources/models/asteroid.obj");
	rend->setTexPath("../resources/textures/asteroid.png");

	tf->setValue("Position", glm::vec3(4.0f, -4.0f, -20.0f));
	tf->setValue("Rotation", glm::vec3(0.0f, 1.0f, 0.0f));
	tf->setValue("Scale", glm::vec3(2.0f, 2.0f, 2.0f));

	id->setID("Asteroid");

	//gc->setSize(glm::vec3(1, 1, 1));
}

void AsteroidObject::changePos(glm::vec3 newPos)
{
	tf->setValue("Position", newPos);
}
