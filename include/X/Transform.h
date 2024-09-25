#ifndef X_TRANSFORM_H
#define X_TRANSFORM_H

#include "raylib.h"

namespace X
{
struct Transform
{
    Transform();
    Transform(const Vector2& position, const Vector2& rotation, const Vector2 &scale);
    Transform(const Vector2& position);

    Vector2 position;
    Vector2 rotation;
    Vector2 scale;
};
}

#endif // !X_TRANSFORM_H
