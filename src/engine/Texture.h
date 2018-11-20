#ifndef ENGINE_TEXTURE_H
#define ENGINE_TEXTURE_H

#include <GL/glew.h>
#include <glm.hpp>

#include <string>

namespace engine
{
	class Texture
	{
		private:
			GLuint id;
			glm::vec2 size;

		public:
			Texture(std::string path);
			glm::vec2 getSize();
			GLuint getId();

	};
}

#endif