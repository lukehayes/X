#include "X/App.h"
#include "X/Gfx/Renderer.h"
#include "X/Mesh/Mesh.h"

constexpr int WIN_MULT   = 4;
constexpr int WIN_WIDTH  = 320 * WIN_MULT;
constexpr int WIN_HEIGHT = 180 * WIN_MULT;

int main(int argc, char *argv[]) {
	// ------------------------------------------------------------------------
	// Set initial state here.

	bool isRunning = true;

	X::App app(WIN_WIDTH, WIN_HEIGHT);


	X::Gfx::Renderer renderer;

	X::Mesh::Mesh planeMesh = X::Mesh::LoadQuadMesh();
	X::Mesh::Mesh cubeMesh = X::Mesh::LoadCubeMesh();

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

		renderer.Clear(0.2, 0.2, 0.2);
		// renderer.WireFrame();

		// renderer.DrawMesh3D(
		// 	cubeMesh,
		// 	transform,
		// 	{0.65,0.65,0.65}
		// );

		// renderer.DrawCube3DRaw(
		// 	{0,0,0},
		// 	{1,1,1},
		// 	camera,
		// 	default_shader
		// );

		SDL_GL_SwapWindow(app.GetWindow());
	}

	SDL_GL_DestroyContext(app.GetContext());
	SDL_DestroyWindow(app.GetWindow());

	SDL_Quit();
}
