#include "Component.h"

namespace engine
{
	class Player : public Component
	{
		private:
			void move();
			void onBegin();
			void onUpdate();
			int speed = 10;

		public:
			void setSpeed(int newSpeed);
	};
}