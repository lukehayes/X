#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "X/Math/GLM.h"
#include "X/Transform.h"
#include "X/Mesh/Mesh.h"

namespace X::Model
{
class Model
{
public:
	Model(const glm::vec3 &position = {0,0, -0.1f});
	~Model();


	/**
	* Translate the model.
	*
	* @param float angle
	*/
	void Translate(const glm::vec3& position);

	/**
	* Rotate the model on the X axis.
	*
	* @param float angle
	*/
	void RotateX(float angle);

	/**
	* Rotate the model on the Y axis.
	*
	* @param float angle
	*/
	void RotateY(float angle);

	/**
	* Rotate the model on the Z axis.
	*
	* @param float angle
	*/
	void RotateZ(float angle);

	/**
	* Scale the model.
	*
	* @param const glm::vec3& axis    The axis to scale.
	*/
	void Scale(const glm::vec3& axis);

	X::Transform transform;
	glm::vec4 color    = {0.5,0,0.5,1};
	glm::mat4 matrix   = glm::mat4(1.0f);
	float rotAngle     = 10.0f;


};
}

#endif // MODEL_MODEL_H
