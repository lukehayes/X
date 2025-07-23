#ifndef X_CAMERA_H
#define X_CAMERA_H

#include "X/Math/GLM.h"

namespace X::Camera
{
/**
* Base class for all cameras.
*/
class Camera
{
	Camera() {}
	~Camera() {}

	virtual void update(double dt) = 0;
};
}

#endif // !X_CAMERA_H
