#include "X/App.h"
#include "X/Camera/Camera3D.h"
#include "X/Gfx/Renderer.h"
#include "X/Mesh/Mesh.h"
#include "X/Scene/DebugScene.h"

constexpr int WIN_MULT   = 4;
constexpr int WIN_WIDTH  = 320 * WIN_MULT;
constexpr int WIN_HEIGHT = 180 * WIN_MULT;


int main(int argc, char *argv[]) {
	// ------------------------------------------------------------------------
	// Set initial state here.

	bool isRunning = true;

	X::App app(WIN_WIDTH, WIN_HEIGHT);

	X::Camera::Camera3D camera3D;
	X::Gfx::Renderer renderer;

    X::Mesh::Mesh quad = X::Mesh::LoadQuadMesh();

    X::Model::CubeModel cube { {0,0,1,1} };
    X::Model::CubeModel cube2 { {0,0.7,0.2,1} };

    cube.transform.position.x = 3.0f;
    cube2.transform.position.x = -3.0f;


	// END OPENGL ----------------------------------------------------


	X::Scene::DebugScene scene;
	bool canSpin = false;
	bool wireframe = false;

	float deltaTime = 0;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;

	float mx,my;


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

			SDL_GetMouseState(&mx, &my);


			if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.key == SDLK_SPACE) {
					canSpin = !canSpin;
				}
			}

			if (event.type == SDL_EVENT_KEY_DOWN) {
				if (event.key.key == SDLK_G) {
					wireframe = !wireframe;
				}
			}
		}


		static float c = 0.0;
		c+=1;

        cube.transform.position.z = std::sin(c / 10.0f);

		if(wireframe)
		{
			scene.renderer.WireFrameOn();
		}else {
			scene.renderer.WireFrameOff();
		}

        camera3D.shader.use();

        renderer.Clear(1.0f, 1.0f, 1.0f);
        renderer.DrawModel3D(cube);
        renderer.DrawModel3D(cube2);

		SDL_GL_SwapWindow(app.GetWindow());
	}

	SDL_GL_DestroyContext(app.GetContext());
	SDL_DestroyWindow(app.GetWindow());

	SDL_Quit();
}
