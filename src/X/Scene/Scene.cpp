#include "X/Scene/Scene.h"

namespace X::Scene
{
Scene::Scene() : renderer() {}
Scene::~Scene() {}

void
Scene::Update(double delta)
{
}

void
Scene::Render()
{
}

X::Gfx::Renderer
Scene::GetRenderer()
{
	return this->renderer;
}

}
