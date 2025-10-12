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
	* Rotate the model on every axis.
	*
	* @param float angle
        *
	* @param glm::vec3 rotation
	*/
	void Rotate(float angle, const glm::vec3& rotation);

	/**
	* Scale the model.
	*
	* @param const glm::vec3& axis    The axis to scale.
	*/
	void Scale(const glm::vec3& axis);

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

}

#endif // X_TRANSFORM_H
