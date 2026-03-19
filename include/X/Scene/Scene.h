#ifndef X_SCENE_SCENE_H
#define X_SCENE_SCENE_H

#include "X/Gfx/Renderer.h"
#include "X/Model/CubeModel.h"

namespace X::Scene
{
	class Scene
	{
	public:

		virtual void Update(double deltaTime) = 0;

		virtual void Render(float r = 0, float g = 0, float b = 0) = 0;

		X::Gfx::Renderer renderer;
	};
}


#endif // X_SCENE_SCENE_H
