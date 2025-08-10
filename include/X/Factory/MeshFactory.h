#ifndef X_FACTORY_MESH_FACTORY_H
#define X_FACTORY_MESH_FACTORY_H

#include "X/GL/VertexArray.h"
#include "X/GL/VertexBuffer.h"
#include "X/GL/IndexBuffer.h"

namespace X::Factory
{

struct Mesh
{
	Mesh() {}
	X::GL::VertexArray vao;
	X::GL::VertexBuffer vbo;
	X::GL::IndexBuffer ibo;
	GLenum primitive;
};


X::Factory::Mesh CreatePlaneMesh()
{
	Mesh mesh;
	mesh.vao.Bind();

	std::vector<GLfloat> data = {
		0.5f,  0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	X::GL::VertexBuffer vbo{
		GL::ATTRIB_VERTEX_POSITION,
		GL::ATTRIB_VERTEX_COUNT,
		GL::ATTRIB_STRIDE,
		data,
		GL_ARRAY_BUFFER};

	std::vector<unsigned int> indices = {
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	X::GL::IndexBuffer ibo(indices);

	mesh.primitive = GL_TRIANGLES;

	return mesh;
}

}

#endif // !X_FACTORY_MESH_FACTORY_H
