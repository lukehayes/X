#ifndef GAME_LEVEL_LEVEL_H
#define GAME_LEVEL_LEVEL_H
#include "X/Scene/Scene.h"
#include <print>

namespace Game::Level
{

/**
* The base scene class that all 'levels' will inherit from.
*/
class Level : public X::Scene::Scene
{
public:
	Level() {}
	~Level() {}

	/**
	* Update the frame.
	*
	* @param double detla  Delta Time
	*/
	void Update(double delta)
	{
		X::Scene::Scene::Update(delta);
		std::println("Level Update {}", delta);
	}


	/**
	* Render the frame.
	*
	* @return void
	*/
	void Render()
	{
		X::Scene::Scene::Render();

		std::println("Level Update");
		this->renderer.Clear(0,1,1);
	}

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

#endif // !GAME_LEVEL_LEVEL_H
