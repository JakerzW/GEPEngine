#include "Component.h"

#include <memory>

class VertexArray;
class ShaderProgram;

class Renderer
{
	private:
		std::shared_ptr<VertexArray> shape;
		std::shared_ptr<ShaderProgram> shader;

		void onDisplay();

	public:
		void onInit();
};