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

	this->Clear(cv,cv,cv);

	shader.use();


	// glDrawArrays(GL_TRIANGLES, 0,3);

	// renderer.Draw(model, cam, default_shader);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

}
