#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

#include <memory>

namespace engine 
{
	class GameObject;
	class Core;
	class Input;
	class Context;
	class Transform;
	class Camera;

	class Component
	{
		friend class GameObject;

		private:
			bool begun;
			std::weak_ptr<GameObject> gameObject;

			virtual void onInit();
			virtual void onBegin();
			virtual void onUpdate();
			virtual void onDisplay();		

		public:		
			std::shared_ptr<GameObject> getGameObject();
			std::shared_ptr<Core> getCore();
			std::shared_ptr<Input> getInput();
			std::shared_ptr<Context> getContext();
			std::shared_ptr<Transform> getTransform();
			std::shared_ptr<Camera> getCamera();
	};
}

#endif
