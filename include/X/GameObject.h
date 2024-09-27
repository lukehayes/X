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
    GameObject(const Vector2& position, const Color& color);

    
    // Members
    Color color;
};
}


#endif
