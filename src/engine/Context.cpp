#include "context.h"

namespace engine
{
	void Context::update()
	{
		time = SDL_GetTicks();
		difference = time - lastTime;
		deltaTime = difference / 1000.0f;
		lastTime = time;
		
		avgFps = (int)(numFrames / (time / 1000.0f));
		numFrames++;		
	}

	void Context::initTime()
	{
		lastTime = SDL_GetTicks();
		numFrames = 1;
		avgFps = 0;
	}

	float Context::getDeltaTime()
	{
		return deltaTime;
	}

	float Context::getAvgFps()
	{
		return avgFps;
	}
}