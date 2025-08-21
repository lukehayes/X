#ifndef X_SCENE_SCENE_H
#define X_SCENE_SCENE_H
#include "X/Gfx/Renderer.h"

namespace X::Scene
{

/**
* The base scene class that all 'levels' will inherit from.
*/
class Scene
{
public:
	Scene();
	~Scene();

	/**
	* Update the frame.
	*
	* @param double detla  Delta Time
	*/
	virtual void Update(double delta);

	/**
	* Render the frame.
	*
	* @return void
	*/
	virtual void Render();

	/**
	* Get the renderer instance.
	*
	* @return X::Gfx::Renderer
	*/
	inline X::Gfx::Renderer GetRenderer();

private:
	X::Gfx::Renderer renderer;

};

}

#endif // !X_SCENE_SCENE_H
