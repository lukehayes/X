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
	Camera() 
            : projection(glm::mat4(1.0f)),
              view(glm::mat4(1.0f))
            {}

	Camera(const glm::mat4& projection, const glm::mat4& view)
            : projection(projection),
              view(view)
            {}

	~Camera() {}

	virtual void update(double dt) = 0;

	glm::mat4 projection;
	glm::mat4 view;
};
}

#endif // !X_CAMERA_H
