#include "engine/Engine.h"

#include <SDL2\SDL.h>
#include <GL\glew.h>

#include <iostream>

class TestScreen : public Component
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

	void onTick()
	{
		std::cout << "onTick" << std::endl;
	}

	void onDisplay()
	{
		std::cout << "onTick" << std::endl;
	}
};

int main()
{	std::shared_ptr<Core> core = Core::init();	std::shared_ptr<Screen> screen = Screen::init(core, 1280, 720, "My Window");
	screen->setScreenColour(0, 0, 0, 255);
	
	std::shared_ptr<GameObject> e = core->addGameObject();
	std::shared_ptr<TestScreen> ts = e->addComponent<TestScreen>("Green");
	std::shared_ptr<Renderer> mr = e->addComponent<Renderer>();
	std::shared_ptr<Renderer> mr2 = e->getComponent<Renderer>();

	core->start();

	return 0;
}