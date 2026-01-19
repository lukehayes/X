#include "X/Gfx/Color.h"

namespace X::Gfx
{

Color::Color() : r(1), g(0), b(1), a(1) {}

Color::Color(float r, float g, float b) : r(r), g(g), b(b), a(1) {}

Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

}

