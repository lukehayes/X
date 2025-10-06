#ifndef X_TRANSFORM_H
#define X_TRANSFORM_H

#include "X/Math/GLM.h"

namespace X
{
struct Transform
{
	Transform();
	Transform(glm::vec3 position);
	Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale);

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

}

#endif // X_TRANSFORM_H
