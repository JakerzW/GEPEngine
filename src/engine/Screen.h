#include <SDL2\SDL.h>
#include <GL\glew.h>

#include <string>
#include <memory>

class Core;

class Screen 
{
	private:
		int width;
		int height;
		SDL_Window* window;
		std::weak_ptr<Core> core;

	public:
		void init(std::weak_ptr<Core> corePtr, int width, int height, const char* name);
		int getWidth();
		int getHeight();
};