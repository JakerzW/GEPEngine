#include "Screen.h"
#include "Core.h"

namespace engine
{
	std::shared_ptr<Core> Screen::getCore()
	{
		return core.lock();
	}

	std::shared_ptr<Screen> Screen::init(std::weak_ptr<Core> corePtr, int sWidth, int sHeight, const char* name)
	{
		std::shared_ptr<Screen> rtn = std::make_shared<Screen>();

		rtn->width = sWidth;
		rtn->height = sHeight;

		rtn->core = corePtr;

		if (SDL_Init(SDL_INIT_VIDEO < 0))
		{
			throw std::exception();
		}

		rtn->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			rtn->width, rtn->height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!SDL_GL_CreateContext(rtn->window))
		{
			throw std::exception();
		}

		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		return rtn;
	}

	void Screen::setScreenColour(int r, int g, int b, int a)
	{
		colours = glm::vec4(r, g, b, a);
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
	}

	void Screen::setupWindow()
	{
		SDL_GetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Screen::drawWindow()
	{
		SDL_GL_SwapWindow(window);
	}

	int Screen::getWidth()
	{
		return width;
	}

	int Screen::getHeight()
	{
		return height;
	}

	float Screen::getRatio()
	{
		return ((float)width / (float)height);
	}

}