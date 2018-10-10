#include <GL\glew.h>
#include <glm.hpp>

#include <vector>
#include <string>
#include <memory>

class VertexBuffer;

class VertexArray
{
	private:
		GLuint id;
		bool dirty;
		std::vector<std::shared_ptr<VertexBuffer>> buffers;

	public:
		VertexArray();
		void setBuffer(std::string attribute, std::weak_ptr<VertexBuffer> buffer);
		int getVertexCount();
		GLuint getId();
};