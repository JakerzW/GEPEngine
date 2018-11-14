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
		std::cout << "onUpdate" << std::endl;
	}

	void onDisplay()
	{
		std::cout << "onDisplay" << std::endl;
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

	std::shared_ptr<engine::GameObject> cube = core->addGameObject();
	std::shared_ptr<engine::Renderer> cubeRend = cube->addComponent<engine::Renderer>();
	std::shared_ptr<engine::Transform> cubeTf = cube->addComponent<engine::Transform>();

	cubeRend->setObjPath("../resources/models/cube.obj");
	cubeRend->setTexPath("../resources/textures/cube.png");

	cubeTf->setValue("Position", glm::vec3(4.0f, 0.0f, -20.0f));
	cubeTf->setValue("Rotation", glm::vec3(0.0f, 1.0f, 0.0f));
	cubeTf->setValue("Scale", glm::vec3(2.0f, 2.0f, 2.0f));

	core->start();

	return 0;
}