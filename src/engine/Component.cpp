#include "Component.h"
#include "GameObject.h"
#include "Core.h"
#include "Context.h"
#include "Input.h"
#include "Transform.h"
#include "Camera.h"
#include "Screen.h"
#include "Collision.h"
#include "ID.h"

namespace engine 
{
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
		return gameObject.lock();
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return getGameObject()->getCore();
	}

	std::shared_ptr<Input> Component::getInput()
	{
		return getGameObject()->getCore()->getInput();
	}

	std::shared_ptr<Context> Component::getContext()
	{
		return getGameObject()->getCore()->getContext();
	}

	std::shared_ptr<Transform> Component::getTransform()
	{
		return getGameObject()->getComponent<Transform>();
	}

	std::shared_ptr<Camera> Component::getCamera()
	{
		return getGameObject()->getCore()->getCamera();
	}
	std::shared_ptr<Screen> Component::getScreen()
	{
		return getGameObject()->getCore()->getScreen();
	}
	std::shared_ptr<Collision> Component::getCollision()
	{
		return getGameObject()->getComponent<Collision>();
	}
	std::shared_ptr<ID> Component::getId()
	{
		return getGameObject()->getComponent<ID>();
	}
}
