#include "X/Gfx/Renderer.h"
#include "glad/glad.h"

#include "X/Global.h"
extern X::Global global;

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
    X::Mesh::Mesh* mesh = global.factory.GetMesh("Cube");
    
    mesh->vertex_array.Bind();
    mesh->vertex_buffer.Bind();
    mesh->index_buffer.Bind();

    shader.use();
    shader.SetUniformMat4(cam.projection, "projection");
    shader.SetUniformMat4(cam.view,       "view");
    shader.SetUniformMat4(model.matrix,   "model");
    shader.setUniformVec4(model.color,    "color");

    glDrawElements(GL_TRIANGLES, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);

}
}
