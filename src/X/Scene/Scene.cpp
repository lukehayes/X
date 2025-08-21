#include "X/Scene/Scene.h"
#include <print>

namespace X::Scene
{
Scene::Scene() : renderer() {}
Scene::~Scene() {}

void
Scene::Update(double delta)
{
	std::println("Scene Update {}", delta);
}

void
Scene::Render()
{
	std::println("Scene Render");
	//this->renderer.Clear(0,0,1);
}

X::Gfx::Renderer
Scene::GetRenderer()
{
	return this->renderer;
}

}
