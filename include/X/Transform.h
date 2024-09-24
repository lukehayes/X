#ifndef XX_TRANSFORM_H
#define XX_TRANSFORM_H

#include <glm/glm.hpp>

namespace XX
{

class Transform
{
public:

    Transform();
    Transform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3 &scale);
    Transform(const glm::vec3& position);

    void setPosition(const glm::vec3& position);
    void setRotation(const glm::vec3& rotation);

    void setRotation(double x, double y, double z);

    void setScale(const glm::vec3& scale);

    glm::vec3 getPosition() const;
    glm::vec3 getRotation() const;
    glm::vec3 getScale()    const;

private:
    glm::vec3 mPosition;
    glm::vec3 mRotation;
    glm::vec3 mScale;
};
}

#endif // !XX_TRANSFORM_H
