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
Renderer::Draw(X::Model::Model& model)
{
    X::Mesh::Mesh* mesh = global.factory.GetMesh("Plane");

    mesh->vertex_array.Bind();
    mesh->vertex_buffer.Bind();
    mesh->index_buffer.Bind();

    shader->use();
    shader->SetUniformMat4(camera3D->projection, "projection");
    shader->SetUniformMat4(camera3D->view,       "view");
    shader->SetUniformMat4(model.matrix,   "model");
    shader->setUniformVec4(model.color,    "color");

    glDrawElements(mesh->primitive, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);

}

void 
Renderer::DrawPixel2D(const glm::vec2& position, const glm::vec4& color)
{
    X::Model::Model model;
    model.Translate({position.x, position.y, -1});
    model.Scale({1, 1, 1});

    X::Mesh::Mesh* mesh = global.factory.GetMesh("Plane");

    mesh->vertex_array.Bind();

    shader->use();
    shader->SetUniformMat4(camera2D->projection, "projection");
    shader->SetUniformMat4(camera2D->view,       "view");
    shader->SetUniformMat4(model.matrix,   "model");
    shader->setUniformVec4(color,    "color");

    glDrawElements(mesh->primitive, mesh->GetIndexCount(), GL_UNSIGNED_INT, 0);
}

}
