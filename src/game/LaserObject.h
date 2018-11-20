#include "engine/Engine.h"

#include <memory>

class LaserObject : public engine::GameObject
{
	private:
		int speed = 50; 
		std::shared_ptr<engine::Transform> tf;

	public:
		LaserObject(std::shared_ptr<engine::Core> corePtr);
		void setStart(glm::vec3 position);
};