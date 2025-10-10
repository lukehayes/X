#ifndef X_CAMERA_H
#define X_CAMERA_H

#include "X/Math/GLM.h"
#include <glm/ext/matrix_float4x4.hpp>

namespace X::Camera
{
/**
* Base class for all cameras.
*/
class Camera
{
public:
	Camera() ;
	Camera(const glm::mat4& projection, const glm::mat4& view);
	~Camera();

	virtual void update(double dt) = 0;

        virtual const char* getName();

	glm::mat4 projection;
	glm::mat4 view;

        const char* name = "Camera Base";
};
}

#endif // !X_CAMERA_H
