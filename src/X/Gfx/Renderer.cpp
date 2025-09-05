#include "X/Gfx/Renderer.h"

namespace X::Gfx
{
void
Renderer::Clear(float r, float g, float b)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(r,g,b,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void
Renderer::Draw(X::Model::Model& model, X::Camera::Camera3D& cam, X::GL::Shader& shader)
{
	shader.use();

	shader.SetUniformMat4(cam.projection, "projection");
	shader.SetUniformMat4(cam.view, "view");

	// model.matrix = glm::translate(
	// 	model.matrix,
	// 	model.transform.position
	// );

	shader.SetUniformMat4(model.matrix, "model");
	shader.setUniformVec4(model.color, "color");
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

}
}
