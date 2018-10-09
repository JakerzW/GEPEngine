#include "Renderer.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ShaderProgram.h"

#include <iostream>

void Renderer::onInit()
{
	std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
	positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
	positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
	positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

	std::shared_ptr<VertexBuffer> colours = std::make_shared<VertexBuffer>();
	colours->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	colours->add(glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
	colours->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	shape = std::make_shared<VertexArray>();
	shape->setBuffer("Position", positions);
	shape->setBuffer("Colour", colours);

	shader = std::make_shared<ShaderProgram>("resources/shaders/simple.vert", "resources/shaders/simple.frag");
}

void Renderer::onDisplay()
{
	shader->setUniform("Model", glm::mat4(1.0f));
	shader->setUniform("Projection", glm::mat4(1.0f));
	shader->draw(*shape);
}
