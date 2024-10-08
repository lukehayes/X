#ifndef X_SPRITE_H
#define X_SPRITE_H

#include "X/GameObject.h"
#include "raylib.h"

namespace X
{

struct Sprite : public X::GameObject
{
    Sprite() = delete;
    Sprite(const char* image, const Vector2& position);

    Sprite(const Sprite& other);
    Sprite(Sprite&& other);

    Sprite& operator=(Sprite& other)  = delete;
    Sprite& operator=(Sprite&& other) = delete;

    void update() override;
    void render() override;

    ~Sprite();

    const char* path;
    Texture2D texture;
};
}



#endif
