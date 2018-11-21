#include "ID.h"

engine::ID::ID(std::string newId)
{
	id = newId;
}

std::string engine::ID::getId()
{
	return id;
}
