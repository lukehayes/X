#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/Math/GLM.h"
#include "X/GL/Shader.h"

namespace X::Gfx
{

class Renderer
{
public:

	void Clear(float r, float g, float b);

	void BasicDraw(X::GL::Shader& shader);
};

}

#endif // !X_RENDERER_H
