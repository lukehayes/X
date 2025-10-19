#include "X/Camera/Camera3D.h"

constexpr int WIN_MULT   = 4;
constexpr int WIN_WIDTH  = 320 * WIN_MULT;
constexpr int WIN_HEIGHT = 180 * WIN_MULT;

namespace X::Camera
{
Camera3D::Camera3D()
        : X::Camera::Camera(
	    glm::perspective(45.0f, (float)WIN_WIDTH/(float)WIN_HEIGHT, 0.1f, 1000.0f),
	    glm::mat4(1.0f)
            ),
            transform({0,0,-30.0}),
            eye({0,0,0}),
            up({0,1,0})
{

    this->view = glm::lookAt(
        this->transform.position,
        this->eye,
        this->up
    );
}

Camera3D::~Camera3D() {}

void Camera3D::update(double dt)
{
    static float c = 0.0;
    c += 0.01;
    int mult = 10.0f;

    this->transform.position.x = std::cos(c) * mult;
    this->transform.position.y = std::sin(c) * mult;
    this->transform.position.z = -30 + std::hypot(std::sin(c), c) * mult;

    this->view = glm::lookAt(
        this->transform.position,
        this->eye,
        this->up
    );

}
}
