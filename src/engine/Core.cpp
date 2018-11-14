#include "Core.h"
#include "GameObject.h"
#include "Context.h"
#include "Screen.h"
#include "Input.h"
#include "Camera.h"

#include <GL/glew.h>

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

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);

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

			screen->setupWindow();

			for (std::vector<std::shared_ptr<GameObject> >::iterator it = gameObjects.begin();
				 it != gameObjects.end(); it++)
			{
				(*it)->display();
			}

			screen->drawWindow();

			if (idealFps > deltaTime)
			{
				std::cout << "Delaying..." << std::endl;
				SDL_Delay((idealFps - deltaTime) * 1000.0f);
			}
		}
	}

	void Core::stop()
	{
		running = false;
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

	std::shared_ptr<Camera> Core::addCamera()
	{
		std::shared_ptr<Camera> rtn = std::make_shared<Camera>();
		rtn->core = self;
		rtn->onInit();
		camera = rtn;

		return camera;
	}

	std::shared_ptr<Camera> Core::addCamera(float fov, glm::mat4 firstViewMatrix, glm::vec3 firstPos, glm::vec3 firstRot)
	{
		std::shared_ptr<Camera> rtn = std::make_shared<Camera>();
		rtn->core = self;
		rtn->onInit(fov, firstViewMatrix, firstPos, firstRot);
		camera = rtn;

		return camera;
	}	

	std::shared_ptr<Camera> Core::getCamera()
	{		
		return camera;
	}

	std::shared_ptr<Screen> Core::getScreen()
	{
		return screen;
	}

	void Core::setIdealFps(float fps)
	{
		idealFps = 1.0f / fps;
	}

	std::shared_ptr<Screen> Core::addScreen(int width, int height, const char* windowName)
	{
		std::shared_ptr<Screen> rtn = std::make_shared<Screen>();
		rtn->core = self;
		rtn = rtn->init(self, width, height, windowName);
		screen = rtn;

		return rtn;
	}

}
