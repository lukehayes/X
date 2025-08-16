
#include <SDL3/SDL.h>
#include "X/GL/Shader.h"
#include "X/Math/GLM.h"
#include "X/Camera/Camera3D.h"
#include "X/Gfx/Renderer.h"
#include "X/GL/VertexArray.h"
#include "X/Factory/MeshFactory.h"
#include "X/App.h"
#include <print>



int main(int argc, char *argv[])
{
	// ------------------------------------------------------------------------
	// Set initial state here.

	constexpr int WIN_MULT   = 4;
	constexpr int WIN_WIDTH  = 320 * WIN_MULT;
	constexpr int WIN_HEIGHT = 180 * WIN_MULT;
	bool isRunning           = true;

	X::App app(WIN_WIDTH, WIN_HEIGHT);

	X::Factory::Mesh mesh = X::Factory::CreatePlaneMesh();

	X::GL::Shader default_shader(
		"../assets/shaders/VSH-Camera3D.glsl",
		"../assets/shaders/FSH-Camera3D.glsl"
	);


	X::Gfx::Renderer renderer;
	X::Camera::Camera3D cam;


	int x = 0;
	int y = 0;
	bool camToggled = false;

	float deltaTime = 0;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;

	while (isRunning) {
		SDL_Event event;

		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}

			if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.key == SDLK_SPACE) {
					std::println("SPace");
				}

				if (event.key.key == SDLK_A) {
					x += 1;
				}
				if (event.key.key == SDLK_D) {
					x -= 1;
				}
				if (event.key.key == SDLK_W) {
					y += 1;
				}
				if (event.key.key == SDLK_S) {
					y -= 1;
				}

				if (event.key.key == SDLK_C) {
					camToggled = true;
				}

				if (event.key.key == SDLK_V) {
					camToggled = false;
				}
			}
		}

		// Test basic OPENGL works
		float cv = 0.70;
		renderer.Clear(cv,cv,cv);

		if (camToggled) {
			cam.update(0.1);
		}

		//vao.Bind();
		//mesh.vao.UnBind();
		mesh.vao.Bind();

		renderer.Draw(x,y - 2,0, cam, default_shader, {0,0,0,1});

		renderer.Draw(0,0,0,     cam, default_shader, {0,1,0,1});
		renderer.Draw(5,0,0,     cam, default_shader, {0,0,1,1});
		renderer.Draw(0,5,0,     cam, default_shader, {1,0,1,1});
		renderer.Draw(0,-5,-0,   cam, default_shader, {0,1,1,1});
		renderer.Draw(-5,5, -0,  cam, default_shader, {1,1,0,1});

		SDL_GL_SwapWindow(app.GetWindow());

	}


	SDL_GL_DestroyContext(app.GetContext());
	SDL_DestroyWindow(app.GetWindow());

	SDL_Quit();
}
