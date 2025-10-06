#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/Model/Model.h"
#include "X/Math/GLM.h"
#include "X/GL/Shader.h"
#include "X/Camera/Camera.h"
#include "X/Camera/Camera3D.h"
#include "X/Factory/MeshFactory.h"

namespace X::Gfx
{

class Renderer
{
public:

	void Clear(float r, float g, float b);

	/**
	* Draw whatever is set to the currently bound VAO.
	*/
	void Draw(X::Model::Model& model, X::Camera::Camera3D& cam, X::GL::Shader& shader);
};

}

#endif // !X_RENDERER_H
