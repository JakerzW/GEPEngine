#ifndef ENGINE_CORE_H
#define ENGINE_CORE_H

#include <ext.hpp>

#include <iostream>
#include <memory>
#include <vector>

namespace engine
{
	class GameObject;
	class Context;
	class Screen;
	class Input;
	class Camera;

	class Core
	{
		private:
		bool running;
		float idealFps;
		float deltaTime;
		std::shared_ptr<Context> context;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Input> input;
		std::shared_ptr<Camera> camera;
		std::vector<std::shared_ptr<GameObject>> gameObjects;
		std::weak_ptr<Core> self;

		public:
		static std::shared_ptr<Core> init();
		void start();
		void stop();
		void setIdealFps(float fps);
		std::shared_ptr<Screen> addScreen(int width, int height, const char* windowName);
		std::shared_ptr<Screen> getScreen();
		std::shared_ptr<GameObject> addGameObject();
		std::vector<std::shared_ptr<GameObject>> getGameObjects();
		std::shared_ptr<Camera> addCamera();
		std::shared_ptr<Camera> addCamera(float fov, glm::mat4 firstViewMatrix, glm::vec3 firstPos, glm::vec3 firstRot);
		std::shared_ptr<Camera> getCamera();
		std::shared_ptr<Context> getContext();
		std::shared_ptr<Input> getInput();
	};
}

#endif
