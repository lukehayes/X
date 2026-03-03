#include "X/Gfx/Renderer.h"
#include "X/Camera/Camera3D.h"
#include "X/GL/Shader.h"
#include "X/Mesh/QuadMesh.h"
#include "X/Mesh/Mesh.h"
#include "glad/glad.h"


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
Renderer::WireFrame()
{
	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
}



void
Renderer::BasicDraw(X::GL::Shader& shader)
{
	float cv = 0.70;

	shader.use();

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

void
Renderer::DrawMesh(const X::Mesh::QuadMesh &mesh, X::GL::Shader& shader)
{
	shader.use();
	glDrawElements(GL_TRIANGLES, mesh.indices.size(), GL_UNSIGNED_INT, 0);
}


void
Renderer::DrawCube3D(
	glm::vec3& position,
	glm::vec3& color,
	X::Camera::Camera3D camera,
	X::GL::Shader& shader)
{


	static float c = 0.0;
	c+= 0.5f;
	shader.use();

	X::Mesh::QuadMesh cubeMesh = X::Mesh::LoadCubeMesh();

	cubeMesh.BindVertexArray();

	glm::mat4 model = glm::mat4(1.0f);

	model = glm::translate(model, position);
	model = glm::rotate(model, glm::radians(std::sin(c) * 10.0f), {1,1,1});

	shader.SetUniformMat4(camera.projection, "u_projection");
	shader.SetUniformMat4(camera.view, "u_view");
	shader.SetUniformMat4(model, "u_model");
	shader.setUniformVec3(color, "u_color");

	glDrawElements(GL_TRIANGLES, cubeMesh.indices.size(), GL_UNSIGNED_INT, 0);

}



}
