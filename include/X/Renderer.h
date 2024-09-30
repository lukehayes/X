#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/GameObject.h"
#include "X/Sprite.h"

namespace X
{
struct Renderer
{
    void DrawSprite(X::Sprite* sprite);

    void DrawObject(X::GameObject* object);
};

}


#endif
