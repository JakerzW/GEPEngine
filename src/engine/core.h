#include <memory>
#include <vector>

class GameObject;
class Context;
class Input;

class Core
{
	private:
		bool running;
		std::shared_ptr<Context> context;
		std::shared_ptr<Input> input;
		std::vector<std::shared_ptr<GameObject>> gameObjects;

	public:
		std::shared_ptr<Core> init();
		void start();
		void stop();
		std::shared_ptr<GameObject> addGameObject();	
};
