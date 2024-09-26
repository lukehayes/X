#ifndef X_GAMEOBEJECT_H
#define X_GAMEOBEJECT_H

#include "X/Object.h"

namespace X
{
struct GameObject
{
    Object object;
    // Members
    Color color;
};

GameObject GameObjectCreate(Vector2 pos);
}


#endif
