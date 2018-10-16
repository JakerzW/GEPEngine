#include "Screen.h"
#include "Core.h"

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
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

int Screen::getWidth()
{
	return width;
}

int Screen::getHeight()
{
	return height;
}
