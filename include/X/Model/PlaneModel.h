#ifndef X_MODEL_PLANE_MODEL_H
#define X_MODEL_PLANE_MODEL_H

#include "X/Mesh/Mesh.h"
#include "X/Model/Model.h"

namespace X::Model
{
	class PlaneModel : public Model
	{
	public:
		PlaneModel(const glm::vec4& color) 
			: Model(X::Mesh::LoadQuadMesh(), color) {}
	};
}

#endif // X_MODEL_PLANE_MODEL_H
