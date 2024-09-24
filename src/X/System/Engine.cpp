#include "XX/System/Engine.h"
#include <SDL2/SDL_events.h>
#include "glad/glad.h"

#include "XX/Gfx/Shader.h"

#include "XX/Model/Model.h"
#include "XX/Mesh/Mesh.h"
#include "XX/Mesh/MeshFactory.h"

#include "XX/Gfx/Camera3D.h"
#include "XX/Gfx/Renderer.h"

#include <map>


double c = 0;
int mx = 0;
int my = 0;

extern XX::Mesh::MeshFactory meshFactory;

namespace XX::System
{
Engine::Engine(size_t width, size_t height, std::string title)
	: deltaTime(0.0),
	window(width, height, title)
{
	// TODO Refactor XX::Window into a better more agnostic solution.
}

Engine::~Engine()
{
	SDL_Quit();
}

void
Engine::run()
{
	XX::Mesh::CubeMesh rectangle;

	XX::Gfx::Camera3D camera({0,0,10.0});
	XX::Gfx::Renderer renderer;


	this->running = true;

	SDL_Event event;

	while(this->running)
	{
		while(SDL_PollEvent(&event) != 0)
		{
			switch(event.type)
			{
				case SDL_KEYDOWN:
					printf("Key Down \n");
				break;
				case SDL_MOUSEMOTION:
					mx = event.motion.x;
					my = event.motion.y;
				break;

				case SDL_QUIT:
					this->running = false;
				break;

			}
		}

		// ----------------------------------------------------------------
		// Start Rendering Here.
		// ----------------------------------------------------------------

		renderer.clear(XX::Gfx::LIGHT_GRAY);

		c += 0.01;

		camera.setPosition({std::cos(c) * 10, std::sin(c) * 10, std::log(c) * 100});
		camera.update(1.0);

		for(int x = 0; x <= 10; x++)
		{
			for(int y = 0; y <= 10; y++)
			{
					renderer.drawRect(meshFactory.getMesh("cube"), {x * 5,0,y * 5}, camera);
			}
		}


		SDL_GL_SwapWindow(window.window);
	}
}
}
