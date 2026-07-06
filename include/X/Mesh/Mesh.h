#ifndef X_MESH_MESH_H
#define X_MESH_MESH_H

#include <vector>
#include "glad/glad.h"
#include "X/GL/GLState.h"

namespace X::Mesh
{

class Mesh
{
public:
	Mesh(
		const std::vector<float> vertices,
		const std::vector<unsigned int> indices
	);

	virtual void Bind() {
		glBindVertexArray(this->vertex_array);
	}

	int GetVertexCount() const { return this->vertices.size(); }
	int GetIndexCount() const { return this->indices.size(); }

	GLuint vertex_array;

private:
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
};


X::GL::GLState LoadCubeMesh();
X::Mesh::Mesh LoadQuadMesh();

}

#endif //X_MESH_MESH_H
