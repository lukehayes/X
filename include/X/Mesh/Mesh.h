#ifndef X_MESH_MESH_H
#define X_MESH_MESH_H

#include "X/GL/VertexArray.h"
#include "X/GL/VertexBuffer.h"
#include "X/GL/IndexBuffer.h"
#include "glad/glad.h"

namespace X::Mesh
{

class Mesh
{
public:

    Mesh(X::GL::VertexArray& vertex_array, X::GL::VertexBuffer& vertex_buffer, X::GL::IndexBuffer& index_buffer);

    Mesh(Mesh&& rhs) = default;
    Mesh& operator=(Mesh&& rhs) = default;

    Mesh(const Mesh& rhs) = delete;
    Mesh& operator=(const Mesh& rhs) = delete;

    /**
    * Get the number of indicies for this mesh.
    *
    * @param size_t
    */
    std::size_t  GetIndexCount();

    /**
    * Get the number of verticies for this mesh.
    *
    * @param size_t.
    */
    std::size_t  GetVertexCount();


    X::GL::VertexArray  vertex_array;
    X::GL::VertexBuffer vertex_buffer;
    X::GL::IndexBuffer  index_buffer;
    GLenum primitive = GL_TRIANGLES;
};

}



#endif //X_MESH_MESH_H
