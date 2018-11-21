#include "ID.h"

namespace engine
{
	void ID::setID(std::string newId)
	{
		id = newId;
	}

	std::string ID::getThisId()
	{
		return id;
	}
}