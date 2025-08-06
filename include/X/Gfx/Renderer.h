#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/Model/Model.h"
#include "X/Math/GLM.h"
#include "X/GL/Shader.h"

namespace X::Gfx
{

class Renderer
{
public:

	void Clear(float r, float g, float b);

	/**
	* Draw whatever is set to the currently bound VAO.
	*/
	void Draw(int x, int y, int z, X::GL::Shader& shader,glm::vec4 color );
};

}

#endif // !X_RENDERER_H
