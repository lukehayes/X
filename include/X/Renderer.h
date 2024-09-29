#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/GameObject.h"
#include "X/Sprite.h"

namespace X
{
struct Renderer
{
    static void DrawSprite(X::Sprite* sprite);

    static void DrawObject(const X::GameObject& object);
};

}


#endif
