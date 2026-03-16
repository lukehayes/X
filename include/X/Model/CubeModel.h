#ifndef X_MODEL_CUBE_MODEL_H
#define X_MODEL_CUBE_MODEL_H

#include "X/Mesh/Mesh.h"
#include "X/Model/Model.h"

namespace X::Model
{
	class CubeModel : public Model
	{
	public:
		CubeModel(const glm::vec4& color)
			: Model(X::Mesh::LoadCubeMesh(), color) {}
	};
}

#endif // X_MODEL_CUBE_MODEL_H
