#include "Core.h"
#include "Screen.h"

std::shared_ptr<Core> Core::init()
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->running = false;
	rtn->self = rtn;	

	return rtn;
}

void Core::start()
{

}

void Core::stop()
{

}

void Core::initScreen(int width, int height, const char * name)
{
	screen = std::make_shared<Screen>();
	screen->init(self, width, height, name);
}

std::shared_ptr<GameObject> Core::addGameObject()
{
	return std::shared_ptr<GameObject>();
}
