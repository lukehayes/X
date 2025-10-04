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

    Mesh(X::GL::VertexArray& vertex_array, X::GL::VertexBuffer& vertex_buffer, X::GL::IndexBuffer& index_buffer)
	: vertex_array(std::move(vertex_array)),
	vertex_buffer(std::move(vertex_buffer)),
	index_buffer(std::move(index_buffer))
    {}

    X::GL::VertexArray  vertex_array;
    X::GL::VertexBuffer vertex_buffer;
    X::GL::IndexBuffer  index_buffer;

    inline std::size_t  GetIndexCount() const { return this->index_buffer.data.size(); }
    inline std::size_t  GetVertexCount() const { return this->vertex_buffer.data.size(); }

    GLenum primitive;
};

}



#endif //X_MESH_MESH_H
