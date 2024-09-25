#include "X/GameObject.h"

namespace X
{
GameObject::GameObject()
        : Object(), color(RED) {}

GameObject::GameObject(const Vector2& position)
        : Object(position),
          color(RED) {}
}

