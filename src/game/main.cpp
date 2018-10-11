#include "engine/Engine.h"

#include <SDL2\SDL.h>
#include <GL\glew.h>

#include <iostream>

int main()
{	std::shared_ptr<Core> core = Core::init();	core->initScreen(800, 600, "Test Screen");	system("PAUSE");
	return 0;
}