#include "X/App.h"
#include "glad/glad.h"

#include "X/Global.h"
#include "X/GL/Shader.h"
#include "X/GL/GLProgram.h"
#include "X/Math/GLM.h"

#include "X/GL/VertexArray.h"
#include "X/GL/VertexBuffer.h"
#include "X/GL/VertexAttribute.h"

extern X::Global global;

constexpr int WIN_MULT   = 4;
constexpr int WIN_WIDTH  = 320 * WIN_MULT;
constexpr int WIN_HEIGHT = 180 * WIN_MULT;

int main(int argc, char *argv[]) {
	// ------------------------------------------------------------------------
	// Set initial state here.

	bool isRunning = true;

	X::App app(WIN_WIDTH, WIN_HEIGHT);

	





	// X::GL::VertexBuffer vertex_buffer{
	// 	X::GL::ATTRIB_VERTEX_POSITION, 
	// 	3, 
	// 	0,
	// 	verticies, 
	// 	GL_ARRAY_BUFFER
	// };

	// vertex_buffer.Bind();

	// std::vector<unsigned int> indices = {
	// 	0, 1, 3, // first triangle
	// 	1, 2, 3  // second triangle
	// };

	// X::GL::IndexBuffer index_buffer{indices};


	X::GL::Shader default_shader(
		"../assets/shaders/VSH-Default.glsl",
		"../assets/shaders/FSH-Default.glsl"
	);


	X::GL::buildGL();

	// X::Model::Model model;
	// model.color = {0.3, 0.3, 0.3, 1};
	// model.Translate({0.5, -0.5, 12});


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
		deltaTime =
			(double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				isRunning = false;
			}

			if (event.type == SDL_EVENT_KEY_DOWN) {

				if (event.key.key == SDLK_SPACE) {
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

		float cv = 0.70;

		static float c = 0.0;

		c += 0.1;

		glClearColor(cv,cv,cv,1);
		glClear(GL_COLOR_BUFFER_BIT);

		default_shader.use();
		default_shader.setUniformVec4({0.2,0.2,0.2,0.2}, "color");
		default_shader.setUniformFloat(c, "time");

		// renderer.Draw(model, cam, default_shader);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		SDL_GL_SwapWindow(app.GetWindow());
	}

	SDL_GL_DestroyContext(app.GetContext());
	SDL_DestroyWindow(app.GetWindow());

	SDL_Quit();
}
