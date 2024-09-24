#ifndef X_ENTITY_H
#define X_ENTITY_H

#include "X/Transform.h"

namespace X
{
struct Entity
{
    Entity();
    Entity(const glm::vec3& position, const XX::Gfx::Color& color);
    Entity(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3 &scale);

    XX::Transform&  getTransform();

    void            setColor(float r, float g, float b, float a);
    void            setColor(XX::Gfx::Color& color);
    glm::vec4       getColor() const;

    XX::Gfx::Shader getShader() const;

    XX::Transform   mTransform;
    XX::Gfx::Color  mColor;
};
}


#endif
