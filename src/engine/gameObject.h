#include <memory>
#include <vector>

#include <engine\component.h>

class GameObject
{
	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		void update();
		void display();

	public:
		std::shared_ptr<Core> getCore();
		void addComponent();

};