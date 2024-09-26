#include "X/Object.h"

namespace X
{
   Object ObjectCreate(Vector2 pos, Vector2 rot, Vector2 scale)
   {
        Object obj;

        obj.transform.position = pos;
        obj.transform.rotation = rot;
        obj.transform.scale    = scale;

        return obj;
   }
}


