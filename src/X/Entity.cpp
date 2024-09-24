#include "XX/Entity.h"

namespace XX
{

Entity::Entity()
    : mTransform(),
      mColor(0.2,0.8f, 0.2f, 1.0f),
      mShader()
{}

Entity::Entity(const glm::vec3& position, const XX::Gfx::Color& color)
    : mTransform(position), mColor(color), mShader() {}

Entity::Entity(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3 &scale)
: mTransform(position, rotation, scale),
  mColor(1,0,0,1),
  mShader()
{}

XX::Transform&
Entity::getTransform()
{
    return this->mTransform;
}

void
Entity::setColor(float r, float g, float b, float a)
{
    this->mColor.r = r;
    this->mColor.g = g;
    this->mColor.b = b;
    this->mColor.a = a;
}

void
Entity::setColor(XX::Gfx::Color& color)
{
    this->mColor.r = color.r;
    this->mColor.g = color.g;
    this->mColor.b = color.b;
    this->mColor.a = color.a;
}


glm::vec4
Entity::getColor() const
{ 
    return glm::vec4(
        this->mColor.r,
        this->mColor.g,
        this->mColor.b,
        this->mColor.a
    ); 
}


XX::Gfx::Shader 
Entity::getShader() const 
{
    return this->mShader;
}


}
