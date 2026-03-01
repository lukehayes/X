#include "X/Gfx/Renderer.h"
#include "X/GL/Shader.h"
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

}
