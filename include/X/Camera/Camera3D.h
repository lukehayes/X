
#ifndef X_CAMERA3D_H
#define X_CAMERA3D_H

#include "X/Math/GLM.h"
#include "X/Transform.h"
#include "X/Camera/Camera.h"

namespace X::Camera
{
class Camera3D : public X::Camera::Camera
{
public:
	Camera3D();
	~Camera3D();

	virtual void update(double dt);

	X::Transform transform;
	glm::vec3 eye;
	glm::vec3 up;
	glm::mat4 projection;
	glm::mat4 view;
};
}

#endif // !X_CAMERA3D_H
