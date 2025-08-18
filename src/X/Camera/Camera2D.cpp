#include "X/Camera/Camera2D.h"

namespace X::Camera
{

constexpr int WIN_MULT   = 4;
constexpr int WIN_WIDTH  = 320 * WIN_MULT;
constexpr int WIN_HEIGHT = 180 * WIN_MULT;

Camera2D::Camera2D(int width, int height)
        :
	  projection( glm::ortho(0,width * 10,0, height * 10) ),
	  view(glm::mat4(1.0f)
        )
{
}

Camera2D::~Camera2D() {}


void
Camera2D::update(double dt)
{}



}
