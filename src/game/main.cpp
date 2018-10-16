#include "engine/Engine.h"

#include <SDL2\SDL.h>
#include <GL\glew.h>

#include <iostream>

int main()
{	std::shared_ptr<Core> core = Core::init();	std::shared_ptr<Screen> screen = Screen::init(core, 800, 600, "Test Screen");
	screen->setScreenColour(0, 0, 0, 255);
	system("PAUSE");
	return 0;
}