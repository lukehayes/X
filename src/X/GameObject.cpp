#include "X/GameObject.h"
#include "X/Game.h"
#include "X/Renderer.h"

namespace X
{
GameObject::GameObject()
        : Object(), color(RED) {}

GameObject::GameObject(const Vector2& position)
        : Object(position),
          color(RED) {}

GameObject::GameObject(const Vector2& position, const Color& color)
        : Object(position), color(color){}


void GameObject::update()
{
    // this->transform.position.x += 1 * game.deltaTime;
}

void GameObject::render()
{
    game->renderer->DrawObject(this);
}

}
