#include "engine/Engine.h"

#include <memory>

class LaserObject : public engine::GameObject
{
	private:
		int speed = 5;

	public:
		LaserObject(std::shared_ptr<engine::Core> corePtr);
};