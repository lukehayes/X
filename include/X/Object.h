#ifndef X_ENTITY_H
#define X_ENTITY_H

#include "raylib.h"
#include "X/Transform.h"

namespace X
{
   struct Object
   {
      Object();
      Object(const Vector2& position);

      X::Transform transform;
   };
}


#endif
