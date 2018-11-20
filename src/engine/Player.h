#ifndef ENGINE_PLAYER_H
#define ENGINE_PLAYER_H

#include "Component.h"

namespace engine
{
	class Player : public Component
	{
		private:
			void move();
			void onBegin();
			void onUpdate();
			int speed = 0.1f;

		public:
			void setSpeed(int newSpeed);
			virtual void shoot();
	};
}

#endif