#include "engine/Engine.h"
#include "AsteroidObject.h"
#include "LaserObject.h"
#include "PlayerController.h"
#include "PlayerObject.h"

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
		//std::cout.flush();
		//std::cout << "FPS: " << getContext()->getAvgFps() << std::endl;
		//std::cout << "onUpdate" << std::endl;
	}

	void onDisplay()
	{
		//std::cout << "onDisplay" << std::endl;
	}
};

int main()
{
	std::shared_ptr<engine::Core> core = engine::Core::init();
	core->setIdealFps(120.0f);

	std::shared_ptr<engine::Screen> screen = core->addScreen(900, 900, "Operation Display");
	screen->setScreenColour(0, 0, 0, 255);

	std::shared_ptr<engine::Camera> camera = core->addCamera();
	
	//std::shared_ptr<engine::GameObject> opDisplay = core->addGameObject();
	//std::shared_ptr<OpDisplay> od = opDisplay->addComponent<OpDisplay>("Start-up successful...");

	std::shared_ptr<PlayerObject> player = std::make_shared<PlayerObject>(core);
	std::shared_ptr<AsteroidObject> asteroid = std::make_shared<AsteroidObject>(core);
	std::shared_ptr<AsteroidObject> asteroid2 = std::make_shared<AsteroidObject>(core);
	asteroid2->changePos(glm::vec3(-3, 3, -20));
	std::shared_ptr<AsteroidObject> asteroid3 = std::make_shared<AsteroidObject>(core);
	asteroid3->changePos(glm::vec3(3, 2, -20));
	std::shared_ptr<AsteroidObject> asteroid4 = std::make_shared<AsteroidObject>(core);
	asteroid4->changePos(glm::vec3(-6, 6, -20));

	core->start();

	return 0;
}