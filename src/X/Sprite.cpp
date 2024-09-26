#include "X/Sprite.h"
#include <stdio.h>

namespace X
{
    Sprite SpriteCreate(const char* image, Vector2 pos)
    {
        Sprite sprite;
        sprite.gameObject = GameObjectCreate(pos);
        sprite.texture = LoadTexture(image);
        return sprite;
    }

    void SpriteDestroy(Sprite* sprite)
    {
        UnloadTexture(sprite->texture);
    }
}



