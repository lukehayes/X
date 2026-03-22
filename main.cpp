#include "X/App.h"
#include "X/Camera/Camera3D.h"
#include "X/Gfx/Renderer.h"
#include "X/Model/Model.h"
#include "X/Model/Generator.h"
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

	std::vector<X::Model::Model> planes = X::Model::GeneratePlaneModels(100,10);

	// END OPENGL ----------------------------------------------------


	X::Scene::DebugScene scene;
	bool canSpin = false;
	bool wireframe = false;

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

		if(wireframe)
		{
			scene.renderer.WireFrameOn();
		}else {
			scene.renderer.WireFrameOff();
		}


		if(canSpin)
		{
			renderer.camera3D.Spin();
			renderer.Clear(1.0,1.0,1.0);

			for(auto &m : planes)
			{
				renderer.DrawModel3D(m);
			}

		}else {
			scene.renderer.camera3D.Spin();
			scene.Update(deltaTime);
			scene.Render(0.2,0.2,0.2);
		}

		SDL_GL_SwapWindow(app.GetWindow());
	}

	SDL_GL_DestroyContext(app.GetContext());
	SDL_DestroyWindow(app.GetWindow());

	SDL_Quit();
}
