#include "X/Transform.h"

namespace X
{
Transform::Transform()
	: position({0,0,0}),
	  rotation({0,0,0}),
	  scale({1,1,1})
{}

Transform::Transform(glm::vec3 position)
	: position(position),
	  rotation({0,0,0}),
	  scale({1,1,1})
{}

Transform::Transform(glm::vec3 position, glm::vec3 rotation, glm::vec3 scale)
	: position(position),
	  rotation(rotation),
	  scale(scale)
{
}

}
