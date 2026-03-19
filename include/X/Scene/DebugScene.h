#ifndef X_SCENE_DEBUG_SCENE_H
#define X_SCENE_DEBUG_SCENE_H

#include "X/Scene/Scene.h"
#include <print>

namespace X::Scene
{
	class DebugScene : public X::Scene::Scene
	{
	public:

		virtual void Update(double deltaTime)
		{
		};

		virtual void Render(float r = 0, float g = 0, float b = 0)
		{
			renderer.Clear(r,g,b);
			// renderer.WireFrame();

			X::Model::CubeModel model1 { {0,0,1,1} };
			X::Model::CubeModel model2 { {0,1,0,1} };
			X::Model::CubeModel model3 { {1,0,0,1} };
			X::Model::CubeModel model4 { {1,1,0,1} };
			X::Model::CubeModel model5 { {0,1,1,1} };

			model2.transform.position.x = 2;
			model3.transform.position.x = -2;
			model4.transform.position.y = -2;
			model5.transform.position.y = 2;

			renderer.DrawModel3D(model1);
			renderer.DrawModel3D(model2);
			renderer.DrawModel3D(model3);
			renderer.DrawModel3D(model4);
			renderer.DrawModel3D(model5);
		};

	};
}




#endif // X_SCENE_DEBUG_SCENE_H
