#ifndef X_RENDERER_H
#define X_RENDERER_H

#include "X/GL/Shader.h"
#include "X/Math/GLM.h"
#include "X/Mesh/QuadMesh.h"
#include "X/Camera/Camera.h"
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
	void WireFrame();

	/**
   * Push everything to the screen - for debugging.
   *
   * @param X::GL::Shader& shader
   */
	void BasicDraw(X::GL::Shader &shader);

	/**
   * Render an instance of a mesh.
   *
   * @param const X::Mesh::QuadMesh& mesh
   * @param X::GL::Shader& shader
   */
	void DrawMesh(const X::Mesh::QuadMesh &mesh, X::GL::Shader &shader);


	/**
   * Stuff all vertex data onto te GPU and draw. VERY INEFFICIENT.
   *
   * @param const glm::vec3& position
   * @param const glm::vec3& color
   * @param X::Camera::Camera3D& camera
   * @param X::GL::Shader& shader
   */
	void DrawCube3DRaw(
		const glm::vec3& position,
		const glm::vec3& color,
		X::Camera::Camera3D& camera,
		X::GL::Shader& shader);

};

} // namespace X::Gfx

#endif // !X_RENDERER_H
