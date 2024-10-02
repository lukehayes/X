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
    virtual void update();
    //

    // // Fixed timestep update.
    virtual void tick();

    //
    virtual void render();
    //
    //
    virtual ~GameObject() {}
    
    // Members
    Color color;
    X::Game* game = nullptr;
};
}


#endif
