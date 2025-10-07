#include "X/Model/Model.h"
#include "X/Math/GLM.h"

namespace X::Model
{
Model::Model(const glm::vec3& position)
	: transform(position, {0,0,0}, {1,1,1})
{}
Model::~Model() {}

void
Model::Translate(const glm::vec3& position)
{
	this->matrix = glm::translate(this->matrix, position);
}

void
Model::RotateX(float angle) {
	this->matrix = glm::rotate(this->matrix, glm::radians(angle), {1,0,0});
}

void
Model::RotateY(float angle) {
	this->matrix = glm::rotate(this->matrix, glm::radians(angle), {0,1,0});
}

void
Model::RotateZ(float angle) {
	this->matrix = glm::rotate(this->matrix, glm::radians(angle), {0,0,1});
}

void
Model::Rotate(float angle, const glm::vec3& rotation)
{
    this->matrix = glm::rotate(this->matrix, glm::radians(angle), rotation);
}

void
Model::Scale(const glm::vec3& axis)
{
	this->matrix = glm::scale(this->matrix, axis);
}

}
