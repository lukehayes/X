#include "X/Gfx/Renderer.h"

namespace X::Gfx
{
void
Renderer::Clear(float r, float g, float b)
{
	glClearColor(r,g,b,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void
Renderer::Draw(int x, int y, int z, X::GL::Shader& shader,glm::vec4 color )
{
	shader.use();

	X::Model::Model model;

	model.matrix = glm::translate(
		model.matrix,
		{x,y,z}
	);

	shader.SetUniformMat4(model.matrix, "model");
	shader.setUniformVec4(color, "color");
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

}
}
