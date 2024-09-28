#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/GameObject.h"
#include "X/Sprite.h"

namespace X
{
struct Renderer
{
    static void DrawSprite(X::Sprite* sprite)
    {
        DrawTextureEx(
            sprite->texture,
            sprite->transform.position,
            0,
            3,
            sprite->color
        );
    }

    static void DrawObject(const X::GameObject& object)
    {
        DrawRectangle(
            object.transform.position.x,
            object.transform.position.y,
            object.transform.scale.x,
            object.transform.scale.y,
            object.color
        );
    }
};

}


#endif
