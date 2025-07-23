
#ifndef X_CAMERA3D_H
#define X_CAMERA3D_H

#include "X/Math/GLM.h"

namespace X::Camera
{
class Camera3D
{
public:
	Camera3D();
	~Camera3D();

	virtual void update(double dt);

	glm::mat4 projection;
	glm::mat4 view;
};
}

#endif // !X_CAMERA3D_H
