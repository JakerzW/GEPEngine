#include "LaserObject.h"
#include "PlayerObject.h"
#include "GameCollider.h"

LaserObject::LaserObject(std::shared_ptr<engine::Core> corePtr)
{
	std::shared_ptr<engine::GameObject> self = corePtr->addGameObject();
	std::shared_ptr<engine::Renderer> rend = self->addComponent<engine::Renderer>();
	tf = self->addComponent<engine::Transform>();
	std::shared_ptr<engine::ID> id = self->addComponent<engine::ID>();
	//std::shared_ptr<GameCollider> gc = self->addComponent<GameCollider>();

	rend->setObjPath("../resources/models/laser.obj");
	rend->setTexPath("../resources/textures/laser.png");

	id->setID("Laser");

	//gc->setSize(glm::vec3(1, 1, 1));
}

void LaserObject::setStart(glm::vec3 position)
{
	tf->setValue("Position", glm::vec3(position.x, position.y + 0.5, position.z)); //Get player's transform
	tf->setMovement(speed, glm::vec3(0.0f, 1.0f, 0.0f));
}
