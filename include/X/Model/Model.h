#ifndef X_MODEL_MODEL_H
#define X_MODEL_MODEL_H

#include "X/Mesh/Mesh.h"
#include "X/Transform.h"

namespace X::Model
{
	class Model
	{
	public:

		Model() {
			this->mesh = X::Mesh::LoadCubeMesh();
		}

		X::Mesh::Mesh mesh;
		X::Transform transform;
	};
}

#endif // X_MODEL_MODEL_H
