#include "glm.hpp"
#include "ext.hpp"

#include <memory>
#include <string>

namespace engine
{
	class VertexArray;
	class ShaderProgram;

	class Renderer : public Component
	{
		private:
		std::shared_ptr<VertexArray> shape;
		std::shared_ptr<ShaderProgram> shader;
		std::string path;

		void onUpdate();
		void onDisplay();

		public:
		void onInit();
		void setObjPath(std::string filePath);
	};
}