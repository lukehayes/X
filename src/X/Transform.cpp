#include "X/Transform.h"

#include "raylib.h"

namespace X
{
Transform::Transform() :
        position({0,0}),
        rotation({0,0}),
        scale({1.0f, 1.0f})
    {}

Transform::Transform(const Vector2& position, const Vector2& rotation, const Vector2 &scale) :
        position(position),
        rotation(rotation),
        scale(scale)
    {}

Transform::Transform(const Vector2& position) :
        position(position),
        rotation({}),
        scale({})
    {}
}
