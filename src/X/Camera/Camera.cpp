#include "X/Camera/Camera.h"
#include <print>

namespace X::Camera
{
Camera::Camera() 
    : projection(glm::mat4(1.0f)),
    view(glm::mat4(1.0f))
{}

Camera::Camera(const glm::mat4& projection, const glm::mat4& view)
    : projection(projection),
    view(view)
{}

Camera::~Camera() {}


const char* Camera::getName() 
{ 
    return this->name; 
}

}

