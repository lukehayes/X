#include "X/App.h"
#include "X/Camera/Camera3D.h"
#include "X/Gfx/Renderer.h"
#include "X/Model/Model.h"
#include "X/Model/Generator.h"

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

	X::Model::Model cubeModel;
	cubeModel.color.r = 0;
	cubeModel.color.g = 1;
	cubeModel.color.b = 0.5;

	std::vector<X::Model::Model> models = X::Model::GenerateModels(10,10);

	// END OPENGL ----------------------------------------------------

	float deltaTime = 0;
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;

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
				}
			}
		}

		camera3D.update(33.0);
		static float c = 0.0;
		c+=1;

		renderer.Clear(0.1,0.1,0.1);
		// renderer.WireFrame();

		renderer.DrawModel3D(cubeModel);

		SDL_GL_SwapWindow(app.GetWindow());
	}

	SDL_GL_DestroyContext(app.GetContext());
	SDL_DestroyWindow(app.GetWindow());

	SDL_Quit();
}
