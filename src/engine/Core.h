#ifndef ENGINE_CORE_H
#define ENGINE_CORE_H

#include <iostream>
#include <memory>
#include <vector>

namespace engine
{
	class GameObject;
	class Context;
	class Screen;
	class Input;

	class Core
	{
		private:
		bool running;
		float idealFps;
		float deltaTime;
		std::shared_ptr<Context> context;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Input> input;
		std::vector<std::shared_ptr<GameObject>> gameObjects;
		std::weak_ptr<Core> self;

		public:
		static std::shared_ptr<Core> init();
		void start();
		void stop();
		void initScreen(int width, int height, const char* name);
		void setIdealFps(float fps);
		std::shared_ptr<GameObject> addGameObject();
		std::vector<std::shared_ptr<GameObject>> getGameObjects();
		std::shared_ptr<Context> getContext();
	};
}

#endif
