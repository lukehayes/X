#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "X/Math/GLM.h"
#include "X/Transform.h"

namespace X::Model
{
class Model
{
public:
	Model(const glm::vec3 &position = {0,0, -0.1f});
	~Model();

	void SetMatrix(
		const glm::vec3 &position,
		const glm::vec3 &rotation,
		const glm::vec3 &scale
	);

	glm::mat4 GetMatrix();


	X::Transform transform;
	glm::vec4 color    = {0.5,0,0.5,1};
	glm::mat4 matrix   = glm::mat4(1.0f);

};
}

#endif // MODEL_MODEL_H
