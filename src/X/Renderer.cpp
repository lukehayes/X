#include "X/Renderer.h"

namespace X
{
    void Renderer::DrawSprite(X::Sprite* sprite)
    {
        DrawTextureEx(
            sprite->texture,
            sprite->transform.position,
            0,
            3,
            sprite->color
        );
    }

    void DrawObject(const X::GameObject& object)
    {
        DrawRectangle(
            object.transform.position.x,
            object.transform.position.y,
            object.transform.scale.x,
            object.transform.scale.y,
            object.color
        );
    }
}
