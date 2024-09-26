#ifndef X_SPRITE_H
#define X_SPRITE_H

#include "X/GameObject.h"
#include "raylib.h"

namespace X
{
    struct Sprite
    {
        GameObject gameObject;
        Texture2D texture;
    };

    Sprite SpriteCreate(const char* image, Vector2 pos);
    void SpriteDestroy(Sprite* sprite);
}

#endif
