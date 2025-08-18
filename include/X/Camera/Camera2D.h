#ifndef X_CAMERA2D_H
#define X_CAMERA2D_H

#include "X/Math/GLM.h"

namespace X::Camera
{
class Camera2D
{
public:
	Camera2D(int width, int height);
	~Camera2D();

	void update(double dt);

	glm::mat4 projection;
	glm::mat4 view;
};
}

#endif // !X_CAMERA2D_H
