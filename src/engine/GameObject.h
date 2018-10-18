#ifndef ENGINE_GAMEOBJECT_H
#define ENGINE_GAMEOBJECT_H

#include <memory>
#include <vector>

#define ADDCOMPONENT \
		std::shared_ptr<T> rtn = std::make_shared<T>(); \
		rtn->gameObject = self; \
		rtn->begun = false; \
		components.push_back(rtn);

class Core;
class Component;

class GameObject
{
	private:
	std::vector<std::shared_ptr<Component>> components;	

	public:
	//Move these into a namespace
	std::weak_ptr<GameObject> self;
	std::weak_ptr<Core> core;
	void update();
	void display();


	template <typename T>
	std::shared_ptr<T> getComponent()
	{
		for (size_t i = 0; i < components.size(); i++)
		{
			std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i));

			if (tst)
			{
				return tst;
			}
		}

		throw std::exception();
	}

	template <typename T>
	std::shared_ptr<T> addComponent()
	{
		ADDCOMPONENT
			rtn->onInit();

		return rtn;
	}

	template <typename T, typename A>
	std::shared_ptr<T> addComponent(A a)
	{
		ADDCOMPONENT
			rtn->onInit(a);

		return rtn;
	}

	template <typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		ADDCOMPONENT
			rtn->onInit(a, b);

		return rtn;
	}

	std::shared_ptr<Core> getCore();
};

#endif


