#ifndef X_SPRITE_H
#define X_SPRITE_H

#include "X/GameObject.h"
#include "raylib.h"

namespace X
{
struct Sprite : public X::GameObject
{
    Sprite(const char* image, const Vector2& position);
    ~Sprite();
    Texture2D texture;
};
}



#endif
