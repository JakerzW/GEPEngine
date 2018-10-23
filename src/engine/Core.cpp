#include "Core.h"
#include "Screen.h"
#include "GameObject.h"

namespace engine
{
	std::shared_ptr<Core> Core::init()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->running = false;
		rtn->self = rtn;

		return rtn;
	}

	void Core::start()
	{
		running = true;

		while (running)
		{
			SDL_Event event = { 0 };
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}
				if (event.type == SDL_KEYDOWN)
				{
					running = false;
				}
			}

			for (std::vector<std::shared_ptr<GameObject> >::iterator it = gameObjects.begin();
				 it != gameObjects.end(); it++)
			{
				(*it)->update();
			}

			for (std::vector<std::shared_ptr<GameObject> >::iterator it = gameObjects.begin();
				 it != gameObjects.end(); it++)
			{
				(*it)->display();
			}

			//screen->drawWindow();
		}
	}

	void Core::stop()
	{
		running = false;
	}

	void Core::initScreen(int width, int height, const char * name)
	{
		screen = std::make_shared<Screen>();
		screen->init(self, width, height, name);
	}

	std::shared_ptr<GameObject> Core::addGameObject()
	{
		std::shared_ptr<GameObject> rtn = std::make_shared<GameObject>();
		gameObjects.push_back(rtn);
		rtn->self = rtn;
		rtn->core = self;

		return rtn;
	}

	std::vector<std::shared_ptr<GameObject>> Core::getGameObjects()
	{
		return gameObjects;
	}

}
