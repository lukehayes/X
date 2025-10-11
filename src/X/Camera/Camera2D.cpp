#include "X/Camera/Camera2D.h"


namespace X::Camera
{

Camera2D::Camera2D(float width, float height)
        : X::Camera::Camera(
         glm::ortho(width/height, -width/height, -1.0f,1.0f,0.1f,10.0f),
         glm::mat4(1.0f)
        ) {
}

Camera2D::~Camera2D() {}


void
Camera2D::update(double dt)
{}

}
