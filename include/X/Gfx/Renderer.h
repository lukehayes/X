#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/Model/Model.h"
#include "X/Math/GLM.h"
#include "X/GL/Shader.h"
#include "X/Camera/Camera2D.h"
#include "X/Camera/Camera3D.h"

namespace X::Gfx
{

class Renderer
{
public:

	void Clear(float r, float g, float b);

	/**
	* Draw whatever is set to the currently bound VAO.
        *
        * @param X::Model::Model model
	*/
	void Draw(X::Model::Model& model);

	/**
	* Draw whatever is set to the currently bound VAO.
        *
        * @param const glm::vec2 position
	*/
	void DrawPixel2D(const glm::vec2& position);

        X::Camera::Camera3D* camera3D;
        X::Camera::Camera2D* camera2D;
        X::GL::Shader* shader;
};

}

#endif // !X_RENDERER_H
