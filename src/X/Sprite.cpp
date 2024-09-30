#include "X/Sprite.h"
#include "X/Game.h"
#include "X/Renderer.h"

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

void
Sprite::update()
{
    this->transform.position.x += 100 * game->deltaTime;
}

void
Sprite::render()
{
    this->game->renderer->DrawObject(this);
}


Sprite::~Sprite()
{
    UnloadTexture(this->texture);
}

}


