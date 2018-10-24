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
	screen->setScreenColour(0, 0, 0, 255);
	core->setIdealFps(5.0f);
	
	std::shared_ptr<engine::GameObject> e = core->addGameObject();
	std::shared_ptr<TestScreen> ts = e->addComponent<TestScreen>("Green");
	std::shared_ptr<engine::Renderer> mr = e->addComponent<engine::Renderer>();
	std::shared_ptr<engine::Renderer> mr2 = e->getComponent<engine::Renderer>();

	core->start();

	return 0;
}