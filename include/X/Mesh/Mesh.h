#ifndef X_MESH_MESH_H
#define X_MESH_MESH_H

#include "X/GL/VertexArray.h"
#include "X/GL/VertexBuffer.h"
#include "X/GL/IndexBuffer.h"

namespace X::Mesh
{

class Mesh
{
public:

	Mesh() {}

	X::GL::VertexArray vao;
	X::GL::VertexBuffer vbo;
	X::GL::IndexBuffer ibo;

	size_t vertex_count;
	size_t index_count;
	GLenum primitive;
};

}



#endif //X_MESH_MESH_H
