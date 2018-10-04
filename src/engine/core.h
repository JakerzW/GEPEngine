#include <memory>
#include <vector>

#include <engine\gameObject.h>
#include <engine\component.h>
#include <engine\context.h>
#include <engine\input.h>

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
