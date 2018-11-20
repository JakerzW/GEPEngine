#include "engine/Engine.h"

#include <memory>

class PlayerObject : public engine::GameObject
{
	public:
		PlayerObject(std::shared_ptr<engine::Core> corePtr);
	
};