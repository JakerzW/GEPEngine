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

		context = std::make_shared<Context>();
		context->initTime();

		input = std::make_shared<Input>();

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);

		while (running)
		{
			context->update();

			SDL_Event event = { 0 };
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
					case SDL_QUIT:
					{
						running = false;
						break;
					}

					case SDL_KEYDOWN:
					{
						switch (event.key.keysym.sym)
						{
							case SDLK_w:
							{
								input->setKey("W", true);
								break;
							}
							case SDLK_a:
							{
								input->setKey("A", true);
								break;
							}
							case SDLK_s:
							{
								input->setKey("S", true);
								break;
							}
							case SDLK_d:
							{
								input->setKey("D", true);
								break;
							}
							case SDLK_q:
							{
								input->setKey("Q", true);
								break;
							}
							case SDLK_e:
							{
								input->setKey("E", true);
								break;
							}
							case SDLK_UP:
							{
								input->setKey("Up", true);
								break;
							}
							case SDLK_DOWN:
							{
								input->setKey("Down", true);
								break;
							}
							case SDLK_LEFT:
							{
								input->setKey("Left", true);
								break;
							}
							case SDLK_RIGHT:
							{
								input->setKey("Right", true);
								break;
							}
							case SDLK_SPACE:
							{
								input->setKey("Space", true);
								break;
							}
							case SDLK_RETURN:
							{
								input->setKey("Enter", true);
								break;
							}
							case SDLK_ESCAPE:
							{
								input->setKey("Esc", true);
								break;
							}
							break;
						}
						break;
					}

					case SDL_KEYUP:
					{
						switch (event.key.keysym.sym)
						{
							case SDLK_w:
							{
								input->setKey("W", false);
								break;
							}
							case SDLK_a:
							{
								input->setKey("A", false);
								break;
							}
							case SDLK_s:
							{
								input->setKey("S", false);
								break;
							}
							case SDLK_d:
							{
								input->setKey("D", false);
								break;
							}
							case SDLK_q:
							{
								input->setKey("Q", false);
								break;
							}
							case SDLK_e:
							{
								input->setKey("E", false);
								break;
							}
							case SDLK_UP:
							{
								input->setKey("Up", false);
								break;
							}
							case SDLK_DOWN:
							{
								input->setKey("Down", false);
								break;
							}
							case SDLK_LEFT:
							{
								input->setKey("Left", false);
								break;
							}
							case SDLK_RIGHT:
							{
								input->setKey("Right", false);
								break;
							}
							case SDLK_SPACE:
							{
								input->setKey("Space", false);
								break;
							}
							case SDLK_RETURN:
							{
								input->setKey("Enter", false);
								break;
							}
							case SDLK_ESCAPE:
							{
								input->setKey("Esc", false);
								break;
							}
							break;
						}
						break;
					}

				}
			}

			if (input->getKeyDown("Esc"))
			{
				running = false;
				break;
			}

			/*for (std::vector<std::shared_ptr<GameObject> >::iterator it = gameObjects.begin();
				 it != gameObjects.end(); it++)
			{
				(*it)->update();
			}*/

			for (size_t i = 0; i < gameObjects.size(); i++)
			{
				gameObjects.at(i)->update();
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
				//std::cout << "Delaying..." << std::endl;
				unsigned int delay = (idealFps - deltaTime) * 1000.0f;
				SDL_Delay(delay);
			}
		}
	}

	void Core::stop()
	{
		running = false;
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

	std::shared_ptr<Screen> Core::getScreen()
	{
		return screen;
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

	/*std::list<std::shared_ptr<GameObject>> Core::getGameObjects()
	{
		return gameObjects;
	}*/

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

	std::shared_ptr<Context> Core::getContext()
	{
		return context;
	}

	std::shared_ptr<Input> Core::getInput()
	{
		return input;
	}



}
