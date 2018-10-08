#include <memory>

class GameObject;
class Core;
class Input;
class Context;

class Component
{
	private:
		std::weak_ptr<GameObject> gameObject;
		void onInit();
		void onBegin();
		void onUpdate();
		void onDisplay();

	public:
		std::shared_ptr<GameObject> getGameObject();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Input> getInput();
		std::shared_ptr<Context> getContext();
};
