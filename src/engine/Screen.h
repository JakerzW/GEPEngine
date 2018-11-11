#include <SDL2\SDL.h>
#include <GL\glew.h>
#include <ext.hpp>

#include <string>
#include <memory>

namespace engine
{
	class Core;

	class Screen
	{
		friend class Core;

		private:
		int width;
		int height;
		glm::vec4 colours;
		SDL_Window* window;
		SDL_Renderer* renderer;
		std::weak_ptr<Core> core;

		public:
		std::shared_ptr<Screen> init(std::weak_ptr<Core> corePtr, int sWidth, int sHeight, const char* name);
		void setScreenColour(int r, int g, int b, int a);
		void drawWindow();
		int getWidth();
		int getHeight();
		float getRatio();
	};
}