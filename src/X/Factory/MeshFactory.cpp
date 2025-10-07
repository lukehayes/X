#include "X/Factory/MeshFactory.h"
#include <print>

namespace X::Factory
{

MeshFactory::MeshFactory () {}

MeshFactory::~MeshFactory () {

    for(auto& mesh : meshes)
    {
        auto m = mesh.second;

        std::println("Mesh VertexCount: {}", m->GetVertexCount());
        std::println("Mesh IndexCount: {}", m->GetIndexCount());
        std::println("Deleteing Mesh");
        delete m;
        std::println("...........");
    }

}

X::Mesh::Mesh*
MeshFactory::AddMesh(const std::string& key, X::Mesh::Mesh* mesh)
{
    return this->meshes[key] = mesh;
}

X::Mesh::Mesh*
MeshFactory::GetMesh(const std::string& key)
{
    return this->meshes[key];
}

X::Mesh::Mesh*
MeshFactory::CreatePlaneMesh()
{
    std::vector<GLfloat> verticies = {0.5f,  0.5f,  0.0f, 0.5f,  -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f, -0.5f, 0.5f,  0.0f};

    X::GL::VertexArray vertex_array;
    // vertex_array.Bind();

    X::GL::VertexBuffer vertex_buffer{X::GL::ATTRIB_VERTEX_POSITION, 3, 0,
        verticies, GL_ARRAY_BUFFER};

    // vertex_buffer.Bind();

    std::vector<unsigned int> indices = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    X::GL::IndexBuffer index_buffer{indices};

    X::Mesh::Mesh* mesh = new X::Mesh::Mesh{vertex_array, vertex_buffer, index_buffer};

    return mesh;
}

X::Mesh::Mesh* 
MeshFactory::CreateCubeMesh()
{

    std::vector<GLfloat> verticies = {
        -1, -1,  0.5, //0
        1, -1,  0.5, //1
        -1,  1,  0.5, //2
        1,  1,  0.5, //3
        -1, -1, -0.5, //4
        1, -1, -0.5, //5
        -1,  1, -0.5, //6
        1,  1, -0.5  //7
    };

    X::GL::VertexArray vertex_array;
    vertex_array.Bind();


    X::GL::VertexBuffer vertex_buffer {
        GL::ATTRIB_VERTEX_POSITION,
        GL::ATTRIB_VERTEX_COUNT,
        GL::ATTRIB_STRIDE,
        verticies,
        GL_ARRAY_BUFFER};

    vertex_buffer.Bind();

    std::vector<unsigned int> indices = {
        //Top
        2, 6, 7,
        2, 3, 7,

        //Bottom
        0, 4, 5,
        0, 1, 5,

        //Left
        0, 2, 6,
        0, 4, 6,

        //Right
        1, 3, 7,
        1, 5, 7,

        //Front
        0, 2, 3,
        0, 1, 3,

        //Back
        4, 6, 7,
        4, 5, 7
    };

    X::GL::IndexBuffer index_buffer(indices);
    index_buffer.Bind();


    X::Mesh::Mesh* mesh = new X::Mesh::Mesh{vertex_array, vertex_buffer, index_buffer};

    return mesh;
}

}

