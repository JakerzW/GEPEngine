#include <GL\glew.h>
#include <glm.hpp>

#include <vector>

namespace engine
{
	class VertexBuffer
	{
		private:
		GLuint id;
		bool dirty;
		int elements;
		std::vector<GLfloat> data;

		public:
		VertexBuffer();
		void add(glm::vec2 value);
		void add(glm::vec3 value);
		void add(glm::vec4 value);
		int getElements();
		int getDataSize();
		GLuint getId();
	};
}