#include "VertexArray.h"
#include "VertexBuffer.h"

VertexArray::VertexArray()
{
	dirty = false;
	glGenVertexArrays(1, &id);
	buffers.resize(10);
}

void VertexArray::setBuffer(std::string attribute, std::weak_ptr<VertexBuffer> buffer)
{
	if (attribute == "in_Position")
	{
		buffers.at(0) = buffer.lock();
	}
	if (attribute == "in_Color")
	{
		buffers.at(1) = buffer.lock();
	}
	else
	{
		//throw std::exception();
	}

	dirty = true;
}

int VertexArray::getVertexCount()
{
	return buffers.at(0)->getDataSize() / buffers.at(0)->getElements();
}

GLuint VertexArray::getId()
{
	if (dirty)
	{
		glBindVertexArray(id);
		for (size_t i = 0; i < buffers.size(); i++)
		{
			if (buffers.at(i))
			{
				glBindBuffer(GL_ARRAY_BUFFER, buffers.at(i)->getId());

				glVertexAttribPointer(i, buffers.at(i)->getElements(), GL_FLOAT, GL_FALSE, buffers.at(i)->getElements() * sizeof(GLfloat), (void *) 0);

				glEnableVertexAttribArray(i);
			}
			else
			{
				glDisableVertexAttribArray(i);
			}			
		}
	}

	return id;
}
