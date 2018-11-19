#include "context.h"

namespace engine
{
	void Context::update()
	{
		time = SDL_GetTicks();
		difference = time - lastTime;
		deltaTime = difference / 1000.0f;
		lastTime = time;		
	}

	void Context::initTime()
	{
		lastTime = SDL_GetTicks();
	}

	float Context::getDeltaTime()
	{
		return deltaTime;
	}
}