#ifndef X_MESH_MESH_H
#define X_MESH_MESH_H

#include "X/GL/BufferData.h"
#include "X/GL/VertexArray.h"
#include "X/GL/VertexBuffer.h"
#include "X/GL/IndexBuffer.h"
#include "glad/glad.h"

namespace X::Mesh
{

class Mesh
{
public:

	Mesh(
		X::GL::BufferData buffer_data,
		X::GL::VertexArray vertex_array,
		GLenum buffer_type
	) : 
		vao(std::move(vertex_array)),
		buffer_data(std::move(buffer_data))
	{}
	Mesh(Mesh&&) = default;

	X::GL::BufferData   buffer_data;
	X::GL::VertexArray  vao;
	X::GL::VertexBuffer vbo;
	X::GL::IndexBuffer  ibo;

	size_t vertex_count;
	size_t index_count;
	GLenum primitive;
};

}



#endif //X_MESH_MESH_H
