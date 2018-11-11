#include "Renderer.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "ShaderProgram.h"
#include "Texture.h"
#include "Camera.h"
#include "Transform.h"
#include "Screen.h"

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
		objPath = filePath;
		shape = std::make_shared<VertexArray>(objPath);
	}

	void Renderer::setTexPath(std::string filePath)
	{
		texPath = filePath;
		texture = std::make_shared<Texture>(texPath);
	}

	void Renderer::onDisplay()
	{
		shader->setUniform("in_Projection", glm::perspective(glm::radians(45.0f), getScreen()->getRatio(), 0.1f, 100.0f));

		//1. Get camera matrix

		glm::mat4 camera = getCamera()->getProjMatrix();

		//2. Set model's transform components

		camera = glm::mat4(1.0f);
		camera = glm::translate(camera, getTransform()->getValue("Position"));
		//rotation
		camera = glm::scale(camera, getTransform()->getValue("Scale"));
		
		//3. Set the uniforms in the shader

		shader->setUniform("in_Model", camera);
		shader->setUniform("in_Texture", texture);

		//4. Draw using shader

		shader->draw(*shape);
	}
}