#ifndef X_MESH_MESH_H
#define X_MESH_MESH_H

#include <vector>
#include "X/Mesh/QuadMesh.h"

namespace X::Mesh
{

class Mesh
{
public:
	Mesh(
		const std::vector<float> vertices,
		const std::vector<unsigned int> indices
	);

	virtual void Bind() {}

	int GetVertexCount() const { return this->vertices.size(); }
	int GetIndexCount() const { return this->indices.size(); }

private:
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
};


class CubeMesh : public Mesh
{
public:
	CubeMesh(
		const std::vector<float> vertices,
		const std::vector<unsigned int> indices
	) : Mesh(vertices, indices) {}

	GLuint vertex_array;
};


X::Mesh::Mesh LoadCubeMesh();
X::Mesh::Mesh LoadQuadMesh();

}

#endif //X_MESH_MESH_H
