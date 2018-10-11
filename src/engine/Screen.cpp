#include "Screen.h"
#include "Core.h"

void Screen::init(std::weak_ptr<Core> corePtr, int width, int height, const char* name)
{
	core = corePtr;
	
	if (SDL_Init(SDL_INIT_VIDEO < 0))
	{
		throw std::exception();
	}

	window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
							  width, height, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	
	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}
}

int Screen::getWidth()
{
	return width;
}

int Screen::getHeight()
{
	return height;
}
