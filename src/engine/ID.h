#ifndef ENGINE_ID_H
#define ENGINE_ID_H

#include "Component.h"

#include <string>

namespace engine
{
	class ID : public Component
	{
		private:
			std::string id;
		
		public:
			void setID(std::string newId);
			std::string getThisId();
	};
}

#endif