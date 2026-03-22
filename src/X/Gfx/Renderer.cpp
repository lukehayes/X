#include "X/Gfx/Renderer.h"
#include "X/Camera/Camera3D.h"
#include "X/GL/Shader.h"
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
Renderer::WireFrameOn()
{
	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
}

void
Renderer::WireFrameOff()
{
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

void
Renderer::DrawModel3D(X::Model::Model& model)
{
	model.mesh.Bind();

	// ------------------------------------------------------------------------
	// MATRIX TRANSLATE, ROTATE, SCALE
	glm::mat4 modelMat = glm::mat4(1.0f);

	modelMat = glm::translate(modelMat, model.transform.position);

	modelMat = glm::rotate(modelMat, glm::radians(model.transform.rotation.x), {1,0,0});
	modelMat = glm::rotate(modelMat, glm::radians(model.transform.rotation.y), {0,1,0});
	modelMat = glm::rotate(modelMat, glm::radians(model.transform.rotation.z), {0,0,1});

	modelMat = glm::scale(modelMat, {
		model.transform.scale.x,
		model.transform.scale.y,
		model.transform.scale.z
	});

	// ------------------------------------------------------------------------
	// SHADER UNIFORMS
	this->camera3D.shader.use();
	this->camera3D.shader.SetUniformMat4(this->camera3D.projection, "u_projection");
	this->camera3D.shader.SetUniformMat4(this->camera3D.view,       "u_view");
	this->camera3D.shader.SetUniformMat4(modelMat,                  "u_model");
	this->camera3D.shader.setUniformVec3(model.color,               "u_color");

	// ------------------------------------------------------------------------
	// DRAWING
	glDrawElements(GL_TRIANGLES, model.mesh.GetIndexCount(), GL_UNSIGNED_INT, 0);
}


void
Renderer::DrawMesh3D(
		X::Mesh::Mesh &mesh,
		const glm::vec3& position,
		const glm::vec3& color)
{
	this->camera3D.shader.use();

	mesh.Bind();

	static float c = 0.0;
	c += 0.01;

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, position);
	model = glm::rotate(model, glm::radians(std::sin(c) * 100.0f), {1,1,1});

	this->camera3D.shader.SetUniformMat4(this->camera3D.projection, "u_projection");
	this->camera3D.shader.SetUniformMat4(this->camera3D.view,       "u_view");
	this->camera3D.shader.SetUniformMat4(model,             "u_model");
	this->camera3D.shader.setUniformVec3(color,             "u_color");

	glDrawElements(GL_TRIANGLES, mesh.GetIndexCount(), GL_UNSIGNED_INT, 0);
}
}
