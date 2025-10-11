#include "X/App.h"
#include "X/Global.h"
#include "X/Camera/Camera3D.h"
#include "X/Camera/Camera2D.h"
#include "X/Factory/MeshFactory.h"
#include "X/GL/Shader.h"
#include "X/Gfx/Renderer.h"
#include "X/Math/GLM.h"
#include "X/Factory/MeshFactory.h"
#include <SDL3/SDL.h>

#include "X/Model/Model.h"

#include <print>


extern X::Global global;


int main(int argc, char *argv[]) {
    // ------------------------------------------------------------------------
    // Set initial state here.

    constexpr int WIN_MULT   = 4;
    constexpr int WIN_WIDTH  = 320 * WIN_MULT;
    constexpr int WIN_HEIGHT = 180 * WIN_MULT;
    bool isRunning = true;

    X::App app(WIN_WIDTH, WIN_HEIGHT);

    X::Camera::Camera2D* cam2D = new X::Camera::Camera2D(WIN_WIDTH, WIN_HEIGHT);
    X::Camera::Camera3D* cam3D = new X::Camera::Camera3D;
    X::GL::Shader default_shader("../assets/shaders/VSH-Camera3D.glsl",
				 "../assets/shaders/FSH-Camera3D.glsl");

    X::Gfx::Renderer renderer;
    renderer.camera2D = cam2D;
    renderer.camera3D = cam3D;
    renderer.shader = &default_shader;


    X::Mesh::Mesh* planeMesh = global.factory.CreatePlaneMesh();
    global.factory.AddMesh("Plane", planeMesh);

    X::Mesh::Mesh* cubeMesh = global.factory.CreateCubeMesh();
    global.factory.AddMesh("Cube", cubeMesh);


    X::Model::Model model;
    model.color = {0.0, 0.5, 0.0, 1};
    model.Translate({0.1, 0.1, -2});
    model.Scale({1, 1, 1});

    X::Model::Model model2;
    model2.color = {0.5, 0.0, 0.0, 1};
    model2.Translate({0, 0, -3});
    model2.Scale({1, 1, 1});

    int x = 0;
    int y = 0;
    bool camToggled = false;

    float deltaTime = 0;
    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;

    std::vector<X::Model::Model> positions;

    while (isRunning) {
	SDL_Event event;

	LAST = NOW;
	NOW = SDL_GetPerformanceCounter();
	deltaTime =
	    (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

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
		    positions = X::Factory::GenerateEntities(1000, 15);
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
	renderer.Clear(cv, cv, cv);

	if (camToggled) {
	    cam3D->update(0.1);
	}

	static float c = 0.0;

	c += 0.1;

	renderer.Draw(model);
	renderer.Draw(model2);

        renderer.DrawPixel2D({std::sin(c) / 10.0f, std::cos(c) / 10.0});

	for (auto m : positions) {
	    X::Model::Model model;

	    // Temporary crash fix
	    model.transform.position.z = 20.0;
	    model.Translate(m.transform.position);
	    model.color = m.color;
            renderer.Draw(model);
	}

	SDL_GL_SwapWindow(app.GetWindow());
    }

    SDL_GL_DestroyContext(app.GetContext());
    SDL_DestroyWindow(app.GetWindow());

    SDL_Quit();
}
