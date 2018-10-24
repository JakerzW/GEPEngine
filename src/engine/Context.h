#include <SDL2\SDL.h>

namespace engine
{
	class Context
	{
		private:
		float deltaTime;
		float lastTime;
		float time;
		float difference;

		public:
		void initTime();
		float getDeltaTime();
	};
}
