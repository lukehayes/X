#include "X/Model/Model.h"
#include "X/Math/GLM.h"

namespace X::Model {
Model::Model(const glm::vec3 &position)
    : transform(position, {0, 0, 0}, {1, 1, 1}) {}
Model::~Model() {}

void
Model::SetMatrix(
	const glm::vec3 &position,
	const glm::vec3 &rotation,
	const glm::vec3 &scale
){
	this->matrix = glm::rotate(this->matrix, glm::radians(5.0f), {1,1,1});
	// this->matrix = glm::scale(this->matrix, {1.2,1,1});
	this->matrix = glm::translate(this->matrix, position);
}

glm::mat4
Model::GetMatrix()
{
	return this->matrix;
}


} // namespace X::Model
