#include "X/Transform.h"

namespace X
{
Transform::Transform()
	: position({0,0,0}),
	  rotation({0,0,0}),
	  scale({1,1,1})
{}

Transform::Transform(glm::vec3 position)
	: position(position),
	  rotation({0,0,0}),
	  scale({1,1,1})
{}

Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: position(position),
	  rotation(rotation),
	  scale(scale)
{
}

void
Transform::Translate(const glm::vec3& position)
{
    this->position = position;
}

void
Transform::RotateX(float angle)
{
    this->rotation.x = angle;
}

void
Transform::RotateY(float angle)
{
    this->rotation.y = angle;
}

void
Transform::RotateZ(float angle)
{
    this->rotation.z = angle;
}

void
Transform::Rotate(float angle, const glm::vec3& rotation)
{
    this->RotateX(angle);
    this->RotateY(angle);
    this->RotateZ(angle);
}

void
Transform::Scale(const glm::vec3& axis)
{
    this->scale = axis;
}

}
