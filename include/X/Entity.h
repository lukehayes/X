#ifndef XX_ENTITY_H
#define XX_ENTITY_H

#include "XX/Transform.h"
#include "XX/Gfx/Color.h"
#include "XX/Gfx/Shader.h"
#include <glm/glm.hpp>

namespace XX
{
class Entity
{
public:
    Entity();
    Entity(const glm::vec3& position, const XX::Gfx::Color& color);
    Entity(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3 &scale);

    XX::Transform&  getTransform();

    void            setColor(float r, float g, float b, float a);
    void            setColor(XX::Gfx::Color& color);
    glm::vec4       getColor() const;

    XX::Gfx::Shader getShader() const;


private:
    XX::Transform   mTransform;
    XX::Gfx::Color  mColor;
    XX::Gfx::Shader mShader;
};
}


#endif
