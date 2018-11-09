#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "Core.h"
#include "GameObject.h"
#include "Camera.h"

#include <iostream>

namespace engine
{
	void Renderer::onInit()
	{
		std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
		positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
		positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
		positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

		std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
		colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
		colors->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
		colors->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

		if (!shape)	shape = std::make_shared<VertexArray>();
		shape->setBuffer("in_Position", positions);
		shape->setBuffer("in_Color", colors);

		shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	}

	void Renderer::setObjPath(std::string filePath)
	{
		path = filePath;
		shape = std::make_shared<VertexArray>(path);
	}

	void Renderer::onDisplay()
	{
		shader->setUniform("in_Model", glm::mat4(1.0f));
		shader->setUniform("in_Projection", glm::mat4(1.0f));

		//shader->setUniform("in_Model", getCamera()->getProjMatrix());
		//shader->setUniform("in_Texture", getGameObject()->getTexture());

		shader->draw(*shape);
	}
}