#ifndef X_CAMERA2D_H
#define X_CAMERA2D_H

#include "X/Camera/Camera.h"
#include "X/Math/GLM.h"

namespace X::Camera
{
class Camera2D : public X::Camera::Camera
{
public:
	Camera2D(float width, float height);
	~Camera2D();

	void update(double dt);
};
}

#endif // !X_CAMERA2D_H
