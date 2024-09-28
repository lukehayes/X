#include "X/Sprite.h"
#include <stdio.h>

namespace X
{
    Sprite::Sprite(const char* image, const Vector2& position)
          : GameObject(position, WHITE),
            path(image),
            texture(LoadTexture(image)) {}

    Sprite::Sprite(const Sprite& other)
          : GameObject(other.transform.position, WHITE),
            path(other.path),
            texture(LoadTexture(other.path)) {}

    Sprite::Sprite(Sprite&& other)
          : GameObject(other.transform.position, WHITE),
            path(other.path),
            texture(LoadTexture(other.path)) {}


    // Sprite::Sprite& operator=(Sprite& other)
    // {
    //     if(this == &other)
    //     {
    //         return *this;
    //     }
    //
    //     printf("-----------> Sprite Copied \n");
    //     return *this;
    // }
    //
    // Sprite::Sprite& operator=(Sprite&& other)
    // {
    //     printf("-----------> Sprite Move Assigned \n");
    //     return *this;
    // }

    Sprite::~Sprite()
    {
        UnloadTexture(this->texture);
    }
}


