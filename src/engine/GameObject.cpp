#include "GameObject.h"
#include "Core.h"
#include "Component.h"

namespace engine 
{
	void GameObject::update()
	{
		for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin();
			 it != components.end(); it++)
		{
			if (!(*it)->begun)
			{
				(*it)->onBegin();
				(*it)->begun = true;
			}

			(*it)->onUpdate();
		}
	}

	void GameObject::display()
	{
		for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
			 it != components.end(); it++)
		{
			(*it)->onDisplay();
		}
	}

	std::shared_ptr<Core> GameObject::getCore()
	{
		return core.lock();
	}

}

