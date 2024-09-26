#ifndef X_TRANSFORM_H
#define X_TRANSFORM_H

#include "raylib.h"

namespace X
{
struct Transform
{
    Vector2 position;
    Vector2 rotation;
    Vector2 scale;
};

Transform TransformCreate(Vector2 pos, Vector2 rot, Vector2 scale);

}

#endif // !X_TRANSFORM_H
