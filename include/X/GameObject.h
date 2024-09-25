#ifndef X_GAMEOBEJECT_H
#define X_GAMEOBEJECT_H

#include "X/Object.h"

namespace X
{
struct GameObject : public X::Object
{
    // Constructors
    GameObject();
    GameObject(const Vector2& position);
    
    // Members
    Color color;
};
}


#endif
