#ifndef X_GAMEOBEJECT_H
#define X_GAMEOBEJECT_H

#include "X/Object.h"
#include "X/Game.h"

namespace X
{


struct GameObject : public X::Object
{
    // Constructors
    GameObject();
    GameObject(const Vector2& position);
    GameObject(const Vector2& position, const Color& color);

    // // Normal update method - 60FPS.
    virtual void update(double dt);
    //
    // // Fixed timestep update.
    // virtual void tick() = 0;
    //
    virtual void render(X::Game* game);
    //
    //
    virtual ~GameObject() {}
    
    // Members
    Color color;
};
}


#endif
