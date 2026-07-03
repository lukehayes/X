#include "X/App.h"
#include "X/Camera/Camera3D.h"
#include "X/Gfx/Renderer.h"
#include "X/Mesh/Mesh.h"
#include "X/Scene/DebugScene.h"

#include "X/Gfx/Debug.h"

constexpr int WIN_MULT   = 4;
constexpr int WIN_WIDTH  = 320 * WIN_MULT;
constexpr int WIN_HEIGHT = 180 * WIN_MULT;


int main(int argc, char *argv[]) {
	// ------------------------------------------------------------------------
	// Set initial state here.

	bool isRunning = true;

	X::App app(WIN_WIDTH, WIN_HEIGHT);

	X::Gfx::Renderer renderer;

    X::Mesh::Mesh quad = X::Mesh::LoadQuadMesh();

    X::Model::CubeModel cube { {0,0,1,1} };
    X::Model::CubeModel cube2 { {0,0.7,0.2,1} };

    auto cubes = X::Gfx::DebugTestCubes3D(1000, 6);

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
		c+=0.05;

        cube.transform.position.y = 10 * std::cos(c / 10.0f);
        cube.transform.position.z = 10 * std::sin(c / 10.0f);

        cube.transform.rotation.x = 100 * std::cos(c);
        cube.transform.rotation.y = 100 * std::cos(c);
        cube.transform.rotation.z = 100 * std::sin(c);

        cube.color.r = std::sin(c);
        cube.transform.scale = {3,3,3};

		if(wireframe)
		{
			scene.renderer.WireFrameOn();
		}else {
			scene.renderer.WireFrameOff();
		}



        renderer.Clear(1.0f, 1.0f, 1.0f);

        renderer.camera3D.shader.use();

        if (canSpin)
        {
            renderer.camera3D.Spin();
        }


        renderer.DrawModel3D(cube);

        for (auto c : cubes) {
            renderer.DrawModel3D(c);
        }


        renderer.DrawModel3D(cube2);

		SDL_GL_SwapWindow(app.GetWindow());
	}

	SDL_GL_DestroyContext(app.GetContext());
	SDL_DestroyWindow(app.GetWindow());

	SDL_Quit();
}
