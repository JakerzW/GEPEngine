#include <GL/glew.h>
#include <glm.hpp>

#include <string>
#include <vector>
#include <memory>

namespace engine
{
	class VertexArray;
	class Texture;

	struct Sampler
	{
		GLint id;
		std::shared_ptr<Texture> texture;
	};

	class ShaderProgram
	{
		private:
		GLuint id;
		std::vector<Sampler> samplers;

		public:
		ShaderProgram(std::string vert, std::string frag);
		void draw(VertexArray& vertexArray);
		void setUniform(std::string uniform, glm::vec4 value);
		void setUniform(std::string uniform, float value);
		void setUniform(std::string uniform, glm::mat4 value);
		void setUniform(std::string uniform, std::shared_ptr<Texture> texture);
		GLuint getId();
	};
}

