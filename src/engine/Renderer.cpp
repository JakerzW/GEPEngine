#include "Engine.h"

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

	void Renderer::onUpdate()
	{
		std::shared_ptr<Transform> tf = getGameObject()->getComponent<Transform>();
		if (!tf)
		{
			throw std::exception("Transform for GameObject not found.");
		}

		glm::mat4 camera = getGameObject()->getComponent<Camera>()->getProjMatrix();
		if (!cam)
		{
			throw std::exception("Camera for GameObject not found.");
		}		

		camera = glm::translate(cam, tf->getPosition("Position"));
		//camera = glm::rotate(model, angle, tf->getValue("Rotation"));
		camera = glm::scale(cam, tf->getValue("Scale");

		getGameObject()->getComponent<Camera>()->setProjMatrix(camera);
	}

	void Renderer::onDisplay()
	{
		shader->setUniform("in_shape", glm::mat4(1.0f));
		shader->setUniform("in_Projection", glm::mat4(1.0f));
		shader->draw(*shape);
	}
}