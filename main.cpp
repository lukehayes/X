#include "X/App.h"
#include "X/GL/GLState.h"
#include "X/GL/Shader.h"
#include "X/Gfx/Renderer.h"
#include "X/Global.h"
#include "X/Math/GLM.h"
#include "glad/glad.h"

extern X::Global global;

constexpr int WIN_MULT   = 4;
constexpr int WIN_WIDTH  = 320 * WIN_MULT;
constexpr int WIN_HEIGHT = 180 * WIN_MULT;

int main(int argc, char *argv[]) {
	// ------------------------------------------------------------------------
	// Set initial state here.

	bool isRunning = true;

	X::App app(WIN_WIDTH, WIN_HEIGHT);

	X::GL::Shader default_shader {
		"../assets/shaders/VSH-Default.glsl",
		"../assets/shaders/FSH-Default.glsl"
	};

	X::Gfx::Renderer renderer;


	// OPENGL --------------------------------------------------------

	std::vector<float> vertices = {
		0.5f,  0.5f, 0.0f, 1.0f,0.0f,0.0f,
		0.5f, -0.5f, 0.0f,0.0f,1.0f,0.0f,
		-0.5f, -0.5f, 0.0f,0.0f,0.0f,1.0f,
		-0.5f,  0.5f, 0.0f, 1.0f, 1.0f,1.0f
	};  

	std::vector<unsigned int> indices = {
		0,1,3,
		1,2,3
	};


	X::GL::GLState glState;

	X::GL::GenerateVertexArray(&glState);
	X::GL::GenerateVertexBuffer(&glState);
	X::GL::GenerateIndexBuffer(&glState);

	X::GL::SetBufferData(X::GL::ARRAY_BUFFER, glState.vbo, vertices);
	X::GL::SetBufferData(X::GL::ELEMENT_ARRAY_BUFFER, glState.ibo, indices);

	X::GL::SetVertexAttribute(0,3,6,0);
	X::GL::SetVertexAttribute(1,3,6,6);



	// END OPENGL ----------------------------------------------------


	float c = 0.0;

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
				if (event.key.key == SDLK_SPACE)
				{
				}
			}
		}


		c += 0.1;

		default_shader.use();

		default_shader.setUniformVec3(glm::vec3{sin(c),cos(c),1}, "col");

		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.7,0.7,0.7,1.0);

		// glDrawArrays(GL_TRIANGLES, 0,3);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		SDL_GL_SwapWindow(app.GetWindow());
	}

	SDL_GL_DestroyContext(app.GetContext());
	SDL_DestroyWindow(app.GetWindow());

	SDL_Quit();
}
