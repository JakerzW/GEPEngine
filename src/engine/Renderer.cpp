#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

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
		colors->add(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
		colors->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
		colors->add(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

		if (!model)	model = std::make_shared<VertexArray>();
		model->setBuffer("in_Position", positions);
		model->setBuffer("in_Color", colors);

		shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	}

	void Renderer::setObjPath(std::string filePath)
	{
		path = filePath;
		model = std::make_shared<VertexArray>(path);
	}

	void Renderer::onUpdate()
	{
		std::shared_ptr<Transform> trans = getTransform();
		//trans->getPosition();
		//model = getPosition via getTransform via getGameobject
	}

	void Renderer::onDisplay()
	{
		shader->setUniform("in_Model", glm::mat4(1.0f));
		shader->setUniform("in_Projection", glm::mat4(1.0f));
		shader->draw(*model);
	}
}