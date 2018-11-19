#include "engine/Engine.h"

#include <SDL2\SDL.h>
#include <GL\glew.h>

#include <iostream>

class OpDisplay : public engine::Component
{
	public:
	void onInit(std::string input)
	{
		std::cout << "onInit " << input << std::endl;
	}

	void onBegin()
	{
		std::cout << "onBegin" << std::endl;
	}

	void onUpdate()
	{
		//std::cout << "onUpdate" << std::endl;
	}

	void onDisplay()
	{
		//std::cout << "onDisplay" << std::endl;
	}
};

class PlayerObject : public engine::GameObject
{
	public:
		PlayerObject(std::shared_ptr<engine::Core> corePtr)
		{
			std::shared_ptr<engine::GameObject> self = corePtr->addGameObject();
			std::shared_ptr<engine::Renderer> rend = self->addComponent<engine::Renderer>();
			std::shared_ptr<engine::Transform> tf = self->addComponent<engine::Transform>();
			std::shared_ptr<engine::Player> player = self->addComponent<engine::Player>();

			rend->setObjPath("../resources/models/ship.obj");
			rend->setTexPath("../resources/textures/ship.png");

			tf->setValue("Position", glm::vec3(0.0f, -4.0f, -20.0f));
			tf->setValue("Rotation", glm::vec3(0.0f, 1.0f, 0.0f));
			tf->setValue("Scale", glm::vec3(1.0f, 1.0f, 1.0f));

			player->setSpeed(100);
		}		
};

class AsteroidObject : public engine::GameObject
{
	public:
		AsteroidObject(std::shared_ptr<engine::Core> corePtr)
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
};

class LaserObject : public engine::GameObject
{
	public:
		LaserObject(std::shared_ptr<engine::Core> corePtr)
		{
			std::shared_ptr<engine::GameObject> self = corePtr->addGameObject();
			std::shared_ptr<engine::Renderer> rend = self->addComponent<engine::Renderer>();
			std::shared_ptr<engine::Transform> tf = self->addComponent<engine::Transform>();

			//std::shared_ptr<engine::Player> player = self->addComponent<engine::Player>();

			rend->setObjPath("../resources/models/laser.obj");
			rend->setTexPath("../resources/textures/laser.png");

			tf->setValue("Position", glm::vec3(0.0f, -3.0f, -20.0f));
		}
};

int main()
{
	std::shared_ptr<engine::Core> core = engine::Core::init();
	core->setIdealFps(60.0f);

	std::shared_ptr<engine::Screen> screen = core->addScreen(1280, 720, "Operation Display");
	screen->setScreenColour(0, 0, 0, 255);

	std::shared_ptr<engine::Camera> camera = core->addCamera();
	
	std::shared_ptr<engine::GameObject> opDisplay = core->addGameObject();
	std::shared_ptr<OpDisplay> od = opDisplay->addComponent<OpDisplay>("Start-up successful...");

	std::shared_ptr<PlayerObject> player = std::make_shared<PlayerObject>(core);
	std::shared_ptr<AsteroidObject> asteroid = std::make_shared<AsteroidObject>(core);
	std::shared_ptr<LaserObject> laser = std::make_shared<LaserObject>(core);

	core->start();

	return 0;
}