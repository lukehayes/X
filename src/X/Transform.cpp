#include "X/Transform.h"

#include "raylib.h"

constexpr float ENTITY_SCALE = 32;

namespace X
{
Transform::Transform() :
        position({0,0}),
        rotation({0,0}),
        scale({ENTITY_SCALE, ENTITY_SCALE})
    {}

Transform::Transform(const Vector2& position) :
        position(position),
        rotation({0,0}),
        scale({ENTITY_SCALE, ENTITY_SCALE})
    {}

Transform::Transform(const Vector2& position, const Vector2& rotation, const Vector2 &scale) :
        position(position),
        rotation(rotation),
        scale(scale)
    {}

}
