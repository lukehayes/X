
#ifndef X_CAMERA3D_H
#define X_CAMERA3D_H

#include "X/Math/GLM.h"
#include "X/GL/Shader.h"
#include "X/Transform.h"

namespace X::Camera
{
class Camera3D
{
public:
	Camera3D();
	~Camera3D();

	virtual void Update(double dt);

	void Spin();

	X::Transform transform;
	glm::vec3 eye;
	glm::vec3 up;
	glm::mat4 projection;
	glm::mat4 view;

	X::GL::Shader shader {
		"../assets/shaders/VSH-Camera3D.glsl",
		"../assets/shaders/FSH-Camera3D.glsl"};
};
}

#endif // !X_CAMERA3D_H
