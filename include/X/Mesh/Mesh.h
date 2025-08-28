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
		  index_buffer(index_buffer)
	{}

	X::GL::VertexArray vertex_array;
	X::GL::VertexBuffer vertex_buffer;
	X::GL::IndexBuffer index_buffer;

	size_t vertex_count;
	size_t index_count;
	GLenum primitive;
};

}



#endif //X_MESH_MESH_H
