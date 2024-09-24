#include "XX/Transform.h"

namespace XX
{
Transform::Transform() :
        mPosition({0,0,0}),
        mRotation({0,0,0}),
        mScale({1.0f, 1.0f, 1.0f})
    {}

Transform::Transform(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3 &scale) :
        mPosition(position),
        mRotation(rotation),
        mScale(scale)
    {}

Transform::Transform(const glm::vec3& position) :
        mPosition(position),
        mRotation({}),
        mScale({})
    {}


void 
Transform::setPosition(const glm::vec3& position) { this->mPosition = position; }

void 
Transform::setRotation(const glm::vec3& rotation) { this->mRotation = rotation; }

void
Transform::setRotation(double x, double y, double z)
{
    this->mRotation.x = x;
    this->mRotation.y = y;
    this->mRotation.z = z;
}

void 
Transform::setScale(const glm::vec3& scale)       { this->mScale    = scale;    }

glm::vec3 
Transform::getPosition() const { return this->mPosition; }

glm::vec3 
Transform::getRotation() const { return this->mRotation; }

glm::vec3 
Transform::getScale()    const { return this->mScale;    }

}
