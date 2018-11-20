#ifndef ENGINE_CONTEXT_H
#define ENGINE_CONTEXT_H

#include <SDL2\SDL.h>

namespace engine
{
	class Context
	{
		private:
		float deltaTime;
		float lastTime;
		float time;
		float difference;
		int numFrames;
		float avgFps;

		public:
		void update();
		void initTime();
		float getDeltaTime();
		float getAvgFps();
	};
}

#endif
