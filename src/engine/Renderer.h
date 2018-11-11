#include "Component.h"

#include "glm.hpp"
#include "ext.hpp"

#include <memory>
#include <string>

namespace engine
{
	class VertexArray;
	class Texture;
	class ShaderProgram;
	class Camera;

	class Renderer : public Component
	{
		private:
		std::shared_ptr<VertexArray> shape;
		std::shared_ptr<Texture> texture;
		std::shared_ptr<ShaderProgram> shader;
		std::string objPath;
		std::string texPath;

		void onDisplay();

		public:
		void onInit();
		void setObjPath(std::string filePath);
		void setTexPath(std::string filePath);
	};
}