#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/GL/Shader.h"
#include "X/Math/GLM.h"
#include "X/Mesh/Mesh.h"
#include "X/Model/Model.h"
#include "X/Camera/Camera3D.h"

namespace X::Gfx {

class Renderer {
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
	void WireFrameOn();

    /**
     * Disable wireframe mode.
    */
	void WireFrameOff();

    /**
	 * Render an instance of a model.
     *
     * @param const X::Model::Model& model
    */
	void DrawModel3D(X::Model::Model& model);


    /**
	 * Render an instance of a mesh.
     *
     * @param const X::Mesh::QuadMesh& mesh
     * @param const glm::vec3& position
     * @paramconst glm::vec3& color,
    */
	void DrawMesh3D(X::Mesh::Mesh &mesh, const glm::vec3& position, const glm::vec3& color);

	X::Camera::Camera3D camera3D;

};

} // namespace X::Gfx

#endif // !X_RENDERER_H
