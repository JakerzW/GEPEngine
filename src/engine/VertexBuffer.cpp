#include "VertexBuffer.h"

namespace engine
{
	VertexBuffer::VertexBuffer()
	{
		elements = 0;
		dirty = false;
		glGenBuffers(1, &id);

		if (!id)
		{
			throw std::exception();
		}
	}

	void VertexBuffer::add(glm::vec2 value)
	{
		if (!elements)
		{
			elements = 2;
		}

		if (elements != 2)
		{
			throw std::exception();
		}

		data.push_back(value.x);
		data.push_back(value.y);

		dirty = true;
	}

	void VertexBuffer::add(glm::vec3 value)
	{
		if (!elements)
		{
			elements = 3;
		}

		if (elements != 3)
		{
			throw std::exception();
		}

		data.push_back(value.x);
		data.push_back(value.y);
		data.push_back(value.z);

		dirty = true;
	}

	void VertexBuffer::add(glm::vec4 value)
	{
		if (!elements)
		{
			elements = 4;
		}

		if (elements != 4)
		{
			throw std::exception();
		}

		data.push_back(value.x);
		data.push_back(value.y);
		data.push_back(value.z);
		data.push_back(value.w);

		dirty = true;
	}

	int VertexBuffer::getElements()
	{
		return elements;
	}

	int VertexBuffer::getDataSize()
	{
		return data.size();
	}

	GLuint VertexBuffer::getId()
	{
		if (dirty)
		{
			glBindBuffer(GL_ARRAY_BUFFER, id);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), &data.at(0), GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			dirty = false;
		}

		return id;
	}
}