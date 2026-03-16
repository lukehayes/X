#ifndef X_MODEL_MODEL_H
#define X_MODEL_MODEL_H

#include "X/Mesh/Mesh.h"
#include "X/Transform.h"

namespace X::Model
{
	class Model
	{
	public:

		Model(const X::Mesh::Mesh& mesh, const glm::vec4& color)
			: mesh(mesh),
			  color(color),
			  transform()
		{}

		X::Mesh::Mesh mesh;
		glm::vec4 color;
		X::Transform transform;
	};
}

#endif // X_MODEL_MODEL_H
