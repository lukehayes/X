#ifndef X_GAMEOBEJECT_H
#define X_GAMEOBEJECT_H

#include "X/Object.h"

namespace X
{

struct GameObject : public X::Object
{
    GameObject()
        : Object(), color(RED) {}

    GameObject(const Vector2& position)
        : Object(position),
          color(RED) {}

    Color color;
};

}


#endif
