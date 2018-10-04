#include "component.h"

void Component::onInit()
{
}

void Component::onBegin()
{
}

void Component::onUpdate()
{
}

void Component::onDisplay()
{
}

std::shared_ptr<GameObject> Component::getGameObject()
{
	return std::shared_ptr<GameObject>();
}

std::shared_ptr<Core> Component::getCore()
{
	return std::shared_ptr<Core>();
}

std::shared_ptr<Input> Component::getInput()
{
	return std::shared_ptr<Input>();
}

std::shared_ptr<Context> Component::getContext()
{
	return std::shared_ptr<Context>();
}
