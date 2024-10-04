#include "X/GameObject.h"
#include "X/Game.h"
#include "X/Renderer.h"
#include <iostream>
#include <stdio.h>

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
    static float speed = 0.00001;
    this->transform.position.x += 1 * speed;
    printf("Pos %f\n", this->transform.position.x);
    // this->transform.position.y += 0.002;
}

void GameObject::render()
{
    game->renderer->DrawObject(this);
}

}
