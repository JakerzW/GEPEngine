#include "engine/Engine.h"

#include <memory>

class PlayerController : public engine::Player
{
	private:
		bool shotMade;
		void onUpdate();
	
	public:
		void shoot(std::shared_ptr<engine::Core> corePtr);	
};