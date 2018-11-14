#include "input.h"

namespace engine
{
	Input::Input()
	{
		addKey("W");
		addKey("A");
		addKey("S");
		addKey("D");
		addKey("Up");
		addKey("Down");
		addKey("Left");
		addKey("Right");
		addKey("Space");
		addKey("Enter");
		addKey("Esc");
	}

	void Input::setKey(std::string key, bool value)
	{
		for (size_t i = 0; i < keyCodes.size(); i++)
		{
			if (keyCodes.at(i).id == key)
			{
				keyCodes.at(i).pressed = value;
			}
		}
	}

	void Input::addKey(std::string newId)
	{
		Key rtn;
		rtn.id = newId;
		rtn.pressed = false;
		keyCodes.push_back(rtn);
	}

	bool Input::getKey(std::string key)
	{
		for (size_t i = 0; i < keyCodes.size(); i++)
		{
			if (key == keyCodes.at(i).id)
			{
				return keyCodes.at(i).pressed;
			}
		}
	}

	bool Input::getKeyDown(std::string key)
	{
		for (size_t i = 0; i < keyCodes.size(); i++)
		{
			if (key == keyCodes.at(i).id)
			{
				if (keyCodes.at(i).pressed)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}

	bool Input::getKeyUp(std::string key)
	{
		for (size_t i = 0; i < keyCodes.size(); i++)
		{
			if (key == keyCodes.at(i).id)
			{
				if (!keyCodes.at(i).pressed)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}