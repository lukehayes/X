#include "X/Model/Model.h"
#include "X/Math/GLM.h"

namespace X::Model
{
Model::Model(const glm::vec3& position)
	: transform(position, {0,0,0}, {1,1,1})
{}
Model::~Model() {}


}
