#include "Screen.h"
#include "Core.h"

namespace engine
{
	std::shared_ptr<Screen> Screen::init(std::weak_ptr<Core> corePtr, int width, int height, const char* name)
	{
		std::shared_ptr<Screen> rtn = std::make_shared<Screen>();

		rtn->core = corePtr;

		if (SDL_Init(SDL_INIT_VIDEO < 0))
		{
			throw std::exception();
		}

		rtn->window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
									   width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

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
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapWindow(window);
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
}