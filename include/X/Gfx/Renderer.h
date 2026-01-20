#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/Math/GLM.h"
#include "X/GL/Shader.h"

namespace X::Gfx
{

class Renderer
{
public:

	/**
	* Clear the screen with a color.
	*
	* @param float r Red
	* @param float g Green
	* @param float b Blue
	*/
	void Clear(float r, float g, float b);

	/**
	* Enable wireframe mode.
	*/
	void WireFrame();

	/**
	* Push everything to the screen - for debugging.
	*
	* @param X::GL::Shader& shader
	*/
	void BasicDraw(X::GL::Shader& shader);
};

}

#endif // !X_RENDERER_H
