#include "X/Sprite.h"
#include <stdio.h>

namespace X
{
Sprite::Sprite(const char* image, const Vector2 position)
        : GameObject(position),
          texture(LoadTexture(image)) {}

Sprite::~Sprite()
{
    printf("Unloaded Sprite \n");
    UnloadTexture(this->texture);
}
}


