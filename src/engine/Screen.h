#include <SDL2\SDL.h>
#include <GL\glew.h>

#include <string>
#include <memory>

namespace engine
{
	class Core;

	class Screen
	{
		private:
		int width;
		int height;
		SDL_Window* window;
		SDL_Renderer* renderer;
		std::weak_ptr<Core> core;

		public:
		static std::shared_ptr<Screen> init(std::weak_ptr<Core> corePtr, int width, int height, const char* name);
		void setScreenColour(int r, int g, int b, int a);
		void drawWindow();
		int getWidth();
		int getHeight();
	};
}