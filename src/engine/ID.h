#include "Component.h"

#include <string>

namespace engine
{
	class ID : public Component
	{
		private:
			std::string id;
		
		public:
			ID(std::string newId);
			std::string getId();
	};
}