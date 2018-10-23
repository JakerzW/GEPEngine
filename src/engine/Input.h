#include <vector>

namespace engine
{
	class Input
	{
		private:
		std::vector<int> keyCodes;
		int mousePosX;
		int mousePosY;

		public:
		bool getKey(int key);
		bool getKeyDown(int key);
		bool getKeyUp(int key);
	};
}
