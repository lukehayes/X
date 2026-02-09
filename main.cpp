#include "X/App.h"
#include "X/GL/GLProgram.h"
#include "X/GL/Shader.h"
#include "X/Gfx/Renderer.h"
#include "X/Global.h"
#include "X/Math/GLM.h"
#include "glad/glad.h"
#include <print>

extern X::Global global;

constexpr int WIN_MULT = 4;
constexpr int WIN_WIDTH = 320 * WIN_MULT;
constexpr int WIN_HEIGHT = 180 * WIN_MULT;

X::GL::GLProgram glProg;

int main(int argc, char *argv[]) {
  // ------------------------------------------------------------------------
  // Set initial state here.

  bool isRunning = true;

  X::App app(WIN_WIDTH, WIN_HEIGHT);

	 std::vector<float> vertices = {
	0.5f,  0.5f, 0.0f, 1.0f, 1.0f,  1.0f,  
	0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f,  
	-0.5f, -0.5f, 0.0f, 1.0f,1.0f, 1.0f, 
	-0.5f, 0.5f,  0.0f, 1.0f,1.0f, 1.0f

	 };

	std::vector<unsigned int> indices = {
		  0, 1, 3, // first triangle
		  1, 2, 3  // second triangle
	};

	X::GL::Shader default_shader(
		"../assets/shaders/VSH-Default.glsl",
        "../assets/shaders/FSH-Default.glsl"
	);

	std::println("Sizeof indices {}", sizeof(indices.at(0)) * indices.size() );
	std::println("Sizeof indices {}", sizeof(unsigned int) * indices.size() );

	GLuint vao;
	GLuint vbo;
	GLuint ibo;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	glBindVertexArray(vao);

	// ARRAY BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(
		GL_ARRAY_BUFFER, 
		sizeof(vertices.at(0)) * vertices.size(),
		vertices.data(),
		GL_STATIC_DRAW
	);


	// INDEX BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		sizeof(indices.at(0)) * indices.size(),
		indices.data(),
		GL_STATIC_DRAW
	);

	// VERTEX ATTRIB POINTERS
	glVertexAttribPointer(
		GL_ARRAY_BUFFER,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(vertices.at(0)) * 6,
		0
	);
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(
		GL_ARRAY_BUFFER,
		3,
		GL_FLOAT,
		GL_FALSE,
		sizeof(vertices.at(0)) * 6,
		(void*)(sizeof(vertices.at(0)) * 6)
	);
	glEnableVertexAttribArray(1);

  // X::GL::buildGL(&glProg, {0.4,0.4,0.4});

  X::Gfx::Renderer renderer;

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

    // vao.Bind();
    // vbo.Bind();
    // ibo.Bind();
	
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);


	// std::println("Pre Render");
	default_shader.use();

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.7,0.7,0.7,1.0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	// std::println("Post Render");
	
    // renderer.WireFrame();
    // renderer.BasicDraw(default_shader);

    SDL_GL_SwapWindow(app.GetWindow());
  }

  // X::GL::DeleteGLProgram(&glProg);

  SDL_GL_DestroyContext(app.GetContext());
  SDL_DestroyWindow(app.GetWindow());

  SDL_Quit();
}
