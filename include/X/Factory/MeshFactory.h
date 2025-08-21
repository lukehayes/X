#ifndef X_FACTORY_MESH_FACTORY_H
#define X_FACTORY_MESH_FACTORY_H

#include "X/GL/VertexArray.h"
#include "X/GL/VertexBuffer.h"
#include "X/GL/IndexBuffer.h"

#include <vector>
#include "X/Math/GLM.h"


namespace X::Factory
{

struct Entity
{
	glm::vec3 position;
	glm::vec4 color;
};



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

/**
* Generate randomized entites for quick testing.
*
* @static
*
* @param int count The anount if entities to draw.
*
* @param int space The space between each entity.
*
* @return std::vector<Entity>
*/
static std::vector<Entity> generateEntities(int count, int space = 10)
{
	std::vector<Entity> positions;


	for (int i = 0; i<= count; i++)
	{
		float rx = -std::rand() % space + std::rand() % space;
		float ry = -std::rand() % space + std::rand() % space;
		float rz = -std::rand() % space + std::rand() % space;

		float rr = (-std::rand() % 1 + std::rand() % 10)/10.0;
		float rg = (-std::rand() % 1 + std::rand() % 10)/10.0;
		float rb = (-std::rand() % 1 + std::rand() % 10)/10.0;
		float ra = (-std::rand() % 1 + std::rand() % 10)/10.0;

		glm::vec3 pos{rx,ry,rz};
		glm::vec4 color{rr,rg,rb,ra};

		Entity f;
		f.position = pos;
		f.color = color;

		positions.push_back(f);

	}

	return positions;
}

}

#endif // !X_FACTORY_MESH_FACTORY_H
