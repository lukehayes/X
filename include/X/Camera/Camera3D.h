
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
	glm::vec3 position = {0,0,-10.0};
	glm::vec3 eye      = {0,0,0};
	glm::vec3 up       = {0,1,0};
};
}

#endif // !X_CAMERA3D_H
