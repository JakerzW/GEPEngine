#include "Core.h"
#include "GameObject.h"
#include "Context.h"
#include "Screen.h"
#include "Input.h"
#include "Camera.h"

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

		std::shared_ptr<Context> context = std::make_shared<Context>();
		context->initTime();

		while (running)
		{
			deltaTime = context->getDeltaTime();

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

			if (idealFps > deltaTime)
			{
				//std::cout << "Delaying..." << std::endl;
				SDL_Delay((idealFps - deltaTime) * 1000.0f);
			}
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

	std::shared_ptr<Context> Core::getContext()
	{
		return context;
	}

	std::shared_ptr<Camera> Core::getCamera()
	{
		return camera;
	}

	void Core::setIdealFps(float fps)
	{
		idealFps = 1.0f / fps;
	}

}
