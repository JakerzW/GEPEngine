#include "engine/Engine.h"

#include <memory>

class AsteroidObject : public engine::GameObject
{
	public:
		AsteroidObject(std::shared_ptr<engine::Core> corePtr);
	
};