#include "X/Camera/Camera3D.h"


constexpr int WIN_MULT   = 4;
constexpr int WIN_WIDTH  = 320 * WIN_MULT;
constexpr int WIN_HEIGHT = 180 * WIN_MULT;

namespace X::Camera
{
Camera3D::Camera3D()
	: projection( glm::perspective(45.0f, (float)WIN_WIDTH/(float)WIN_HEIGHT, 0.1f, 100.0f) ),
	  view(glm::mat4(1.0f))
{}

Camera3D::~Camera3D() {}

void Camera3D::update(double dt)
{

    static float c = 0.0;
    c += 0.01;

    this->view = glm::lookAt(
        (glm::vec3){std::cos(c) * 10, -std::cos(10) * 10, -10.0f - std::sin(c) * 10},
        (glm::vec3){0,0, std::sin(c) * 10},
        (glm::vec3){0,1,0}
    );

}
}
