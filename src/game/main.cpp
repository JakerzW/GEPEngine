#include "engine/Engine.h"

#include <SDL2\SDL.h>
#include <GL\glew.h>

#include <iostream>

class TestScreen : public engine::Component
{
	public:
	void onInit(std::string color)
	{
		std::cout << "onInit " << color << std::endl;
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
{	std::shared_ptr<engine::Core> core = engine::Core::init();	std::shared_ptr<engine::Screen> screen = engine::Screen::init(core, 1280, 720, "My Window");
	screen->setScreenColour(0, 255, 0, 255);
	core->setIdealFps(60.0f);
	
	std::shared_ptr<engine::GameObject> testScreen = core->addGameObject();
	std::shared_ptr<TestScreen> ts = testScreen->addComponent<TestScreen>("Green");

	std::shared_ptr<engine::GameObject> cube = core->addGameObject();
	std::shared_ptr<engine::Renderer> cubeRend = cube->addComponent<engine::Renderer>();
	//std::shared_ptr<engine::Renderer> cubeTrans = cube->addComponent<engine::Transform>();

	cubeRend->setObjPath("../resources/models/cube.obj");
	//cubeTrans->setTransform(data)...

	core->start();

	return 0;
}