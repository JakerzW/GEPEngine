#ifndef ENGINE_INPUT_H
#define ENGINE_INPUT_H

#include <vector>
#include <string>

namespace engine
{
	struct Key
	{
		std::string id;
		bool pressed;
	};

	class Input
	{
		private:
		std::vector<Key> keyCodes;
		int mousePosX;
		int mousePosY;
		void addKey(std::string newId);

		public:
		Input();
		void setKey(std::string key, bool value);
		bool getKey(std::string key);
		bool getKeyDown(std::string key);
		bool getKeyUp(std::string key);
	};
}

#endif
