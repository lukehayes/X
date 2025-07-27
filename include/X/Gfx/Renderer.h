#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/Model/Model.h"
#include "X/Math/GLM.h"
#include "X/GL/Shader.h"

namespace X::Gfx
{

class Renderer
{
public:

	/**
	* Draw whatever is set to the currently bound VAO.
	*/
	void Draw(int x, int y, int z, X::GL::Shader& shader)
	{
		X::Model::Model model;

		model.matrix = glm::translate(
			model.matrix,
			{x,y,z}
		);

		shader.SetUniformMat4(model.matrix, "model");
		shader.setUniformVec4(model.color, "color");
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	}
};

}

#endif // !X_RENDERER_H
