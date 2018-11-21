#include "PlayerObject.h"
#include "PlayerController.h"
#include "GameCollider.h"

PlayerObject::PlayerObject(std::shared_ptr<engine::Core> corePtr)
{
	std::shared_ptr<engine::GameObject> self = corePtr->addGameObject();
	std::shared_ptr<engine::Renderer> rend = self->addComponent<engine::Renderer>();
	std::shared_ptr<engine::Transform> tf = self->addComponent<engine::Transform>();
	std::shared_ptr<PlayerController> player = self->addComponent<PlayerController>();
	std::shared_ptr<engine::ID> id = self->addComponent<engine::ID>();
	//std::shared_ptr<GameCollider> gc = self->addComponent<GameCollider>();

	rend->setObjPath("../resources/models/ship.obj");
	rend->setTexPath("../resources/textures/ship.png");

	tf->setValue("Position", glm::vec3(0.0f, -4.0f, -20.0f));
	tf->setValue("Rotation", glm::vec3(0.0f, 1.0f, 0.0f));
	tf->setValue("Scale", glm::vec3(1.0f, 1.0f, 1.0f));

	player->setSpeed(10);

	id->setID("Player");
}