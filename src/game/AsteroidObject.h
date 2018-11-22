#include "engine/Engine.h"

#include <memory>

class AsteroidObject : public engine::GameObject
{
	private:
		std::shared_ptr<engine::Transform> tf;

	public:
		AsteroidObject(std::shared_ptr<engine::Core> corePtr);
		void changePos(glm::vec3 newPos);
	
};