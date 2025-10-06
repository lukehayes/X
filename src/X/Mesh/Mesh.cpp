#include "X/Mesh/Mesh.h"


namespace X::Mesh
{
    Mesh::Mesh(X::GL::VertexArray& vertex_array, X::GL::VertexBuffer& vertex_buffer, X::GL::IndexBuffer& index_buffer)
	: vertex_array(std::move(vertex_array)),
	vertex_buffer(std::move(vertex_buffer)),
	index_buffer(std::move(index_buffer))
    {}

    std::size_t Mesh::GetIndexCount() { return this->index_buffer.data.size(); }

    std::size_t  Mesh::GetVertexCount() { return this->vertex_buffer.data.size(); }

}
