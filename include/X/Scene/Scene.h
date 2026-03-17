#ifndef X_SCENE_SCENE_H
#define X_SCENE_SCENE_H

#include <print>

namespace X::Scene
{
	class Scene
	{
	public:

		virtual void Update(double deltaTime)
		{
			std::println("Update Delta: {}", deltaTime);
		};

		double deltaTime;
	};
}


#endif // X_SCENE_SCENE_H
