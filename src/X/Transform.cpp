#include "X/Transform.h"

#include "raylib.h"

constexpr float ENTITY_SCALE = 32;

namespace X
{
    Transform TransformCreate(Vector2 pos, Vector2 rot, Vector2 scale)
    {
        Transform t;
        t.position = pos;
        t.rotation = rot;
        t.scale = scale;

        return t;
    }
}
