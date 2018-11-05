#include "Component.h"

#include <memory>
#include <string>

namespace engine
{
	class VertexArray;
	class ShaderProgram;

	class Renderer : public Component
	{
		private:
		std::shared_ptr<VertexArray> model;
		std::shared_ptr<ShaderProgram> shader;
		std::string path;

		void onDisplay();

		public:
		void onInit();
		void setObjPath(std::string filePath);
	};
}