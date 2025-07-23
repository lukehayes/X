#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "X/Math/GLM.h"

namespace X::Model
{
class Model
{
public:
	Model(const glm::vec3 &position = {0,0, -0.1f});
	~Model();

	glm::vec3 position = {0,0,-0.1f};
	glm::vec3 rotation = {0,0,0};
	glm::vec3 scale = {1,1,1};
	glm::mat4 matrix = glm::mat4(1.0f);
	float rotAngle = 10.0f;
};
}

#endif // MODEL_MODEL_H
