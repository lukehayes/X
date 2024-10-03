#include "X/GameObject.h"
#include "X/Game.h"
#include "X/Renderer.h"
#include <iostream>

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
    std::cout << "Game Object Update: " << game->deltaTime << std::endl;
    // this->transform.position.x += 10 * game->deltaTime;
}

void GameObject::tick()
{
    std::cout << "Game Object Tick: " << std::endl;
    this->transform.position.x += 0.002;
    this->transform.position.y += 0.002;
}

void GameObject::render()
{
    std::cout << "Game Object Render: " << std::endl;
    game->renderer->DrawObject(this);
}

}
