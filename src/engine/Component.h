#ifndef ENGINE_COMPONENT_H
#define ENGINE_COMPONENT_H

#include <memory>


class GameObject;
class Core;
class Input;
class Context;

class Component
{
	private:		
		

	public:
		virtual void onInit();
		virtual void onBegin();
		virtual void onUpdate();
		virtual void onDisplay();

	    bool begun;
		std::weak_ptr<GameObject> gameObject;		
		std::shared_ptr<GameObject> getGameObject();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Input> getInput();
		std::shared_ptr<Context> getContext();
};

#endif
