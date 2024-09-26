#ifndef X_ENTITY_H
#define X_ENTITY_H

#include "raylib.h"
#include "X/Transform.h"

namespace X
{
   struct Object
   {
      X::Transform transform;
   };

   Object ObjectCreate(Vector2 pos, Vector2 rot, Vector2 scale);
}


#endif
