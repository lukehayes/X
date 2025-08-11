#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_timer.h>
#include <iostream>
#include "glad/glad.h"

#include "X/GL/Shader.h"
#include "X/Math/GLM.h"
#include "X/Camera/Camera3D.h"
#include "X/Gfx/Renderer.h"
#include "X/GL/VertexArray.h"
#include "X/Factory/MeshFactory.h"

#include <cstdlib>
#include <ctime>
#include <print>
#include <vector>



int main(int argc, char *argv[])
{
	// ------------------------------------------------------------------------
	// Set initial state here.

	constexpr int WIN_MULT   = 4;
	constexpr int WIN_WIDTH  = 320 * WIN_MULT;
	constexpr int WIN_HEIGHT = 180 * WIN_MULT;

	bool isRunning           = true;

	if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
		std::cout << "Window Context Failed" << std::endl;
		std::cout << "Error:" << SDL_GetError() << std::endl;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

	SDL_Window* window       = SDL_CreateWindow("Title", WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL);
	SDL_GLContext window_ctx = SDL_GL_CreateContext(window);

	SDL_GL_MakeCurrent(window, window_ctx);

	// INITIALIZE GLAD:
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		throw(std::string("Failed to initialize GLAD"));
	}

	if (window == NULL) {

		// In the case that the window could not be made...
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	if (!window_ctx) {
		std::cout << "Window Context Failed" << std::endl;
		std::cout << "Error:" << SDL_GetError() << std::endl;
	}

	X::Factory::Mesh mesh = X::Factory::CreatePlaneMesh();

	X::GL::Shader default_shader {
		"../assets/shaders/VSH-Camera3D.glsl",
		"../assets/shaders/FSH-Camera3D.glsl"
	};


	X::Gfx::Renderer renderer;
	X::Camera::Camera3D cam;

	std::vector<glm::vec3> positions;
	auto n = 10;
	auto space = 10000;

	for(int i =0; i <= space; i++)
	{
		auto rx = 2 * sin(i) * n;
		auto ry = 2 * cos(i) * n;
		//auto ry = -std::rand() % n + std::rand() % n;
		auto rz = -std::rand() % n + std::rand() % n;

		glm::vec3 v{rx,ry,rz};

		positions.push_back(v);
	}


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
		renderer.Clear(0,0,0);

		if (camToggled) {
			cam.update(0.1);
		}

		//vao.Bind();
		//mesh.vao.UnBind();
		mesh.vao.Bind();

		for(auto p : positions)
		{
			renderer.Draw(p.x, p.y - 2, p.z, cam, default_shader, {1,1,1,1});
		}

		renderer.Draw(x,y - 2,0, cam, default_shader, {1,0,0,1});

		//renderer.Draw(0,0,0,     cam, default_shader, {0,1,0,1});
		//renderer.Draw(5,0,0,     cam, default_shader, {0,0,1,1});
		//renderer.Draw(0,5,0,     cam, default_shader, {1,0,1,1});
		//renderer.Draw(0,-5,-0,   cam, default_shader, {0,1,1,1});
		//renderer.Draw(-5,5, -0,  cam, default_shader, {1,1,0,1});

		SDL_GL_SwapWindow(window);

	}



	SDL_GL_DestroyContext(window_ctx);
	SDL_DestroyWindow(window);

	SDL_Quit();
}
