#include "X/App.h"
#include "X/Camera/Camera3D.h"
#include "X/Factory/MeshFactory.h"
#include "X/GL/Shader.h"
#include "X/GL/VertexArray.h"
#include "X/Gfx/Renderer.h"
#include "X/Math/GLM.h"
#include "X/Mesh/Mesh.h"
#include <SDL3/SDL.h>

#include "X/Model/Model.h"

#include <print>

int main(int argc, char *argv[]) {
    // ------------------------------------------------------------------------
    // Set initial state here.

    constexpr int WIN_MULT = 4;
    constexpr int WIN_WIDTH = 320 * WIN_MULT;
    constexpr int WIN_HEIGHT = 180 * WIN_MULT;
    bool isRunning = true;

    X::App app(WIN_WIDTH, WIN_HEIGHT);

    std::vector<GLfloat> verticies = {0.5f,  0.5f,  0.0f, 0.5f,  -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f, -0.5f, 0.5f,  0.0f};

    X::GL::VertexArray vertex_array;
    // vertex_array.Bind();

    X::GL::VertexBuffer vertex_buffer{X::GL::ATTRIB_VERTEX_POSITION, 3, 0,
	verticies, GL_ARRAY_BUFFER};

    // vertex_buffer.Bind();

    std::vector<unsigned int> indices = {
	0, 1, 3, // first triangle
	1, 2, 3  // second triangle
    };

    X::GL::IndexBuffer index_buffer{indices};

    X::Mesh::Mesh mesh{vertex_array, vertex_buffer, index_buffer};

    X::Gfx::Renderer renderer;
    X::Camera::Camera3D cam;
    X::GL::Shader default_shader("../assets/shaders/VSH-Camera3D.glsl",
				 "../assets/shaders/FSH-Camera3D.glsl");

    
    mesh.index_count = indices.size();

    X::Model::Model model;
    model.color = {0.3, 0.3, 0.3, 1};
    model.mesh = &mesh;
    model.transform.position = {0.5, -0.5, -22};

    X::Model::Model model2;
    model2.color = {0.2, 0.2, 0.6, 1};
    model2.mesh = &mesh;
    model2.transform.position = {0, 0.5, 12};

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
		    positions = X::Factory::GenerateEntities(1000, 100);
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
	    cam.update(0.1);
	}

	static float c = 0.0;

	c += 1.0;

	// mesh.vao.Bind();

	vertex_array.Bind();
	vertex_buffer.Bind();
	index_buffer.Bind();

	// index_buffer.Bind();
	// vertex_array.Bind();
	// default_shader.use();

	// model.transform.position.x += cos(c) * 10.0;
	// model.transform.position.z += sin(c) * 10.0;

	renderer.Draw(model, cam, default_shader);
	renderer.Draw(model2, cam, default_shader);

	for (auto m : positions) {
	    X::Model::Model model;
	    model.transform.position.z = 20.0;
	    model.Translate(m.transform.position);
	    model.color = m.color;
	    renderer.Draw(model, cam, default_shader);
	}

	SDL_GL_SwapWindow(app.GetWindow());
    }

    SDL_GL_DestroyContext(app.GetContext());
    SDL_DestroyWindow(app.GetWindow());

    SDL_Quit();
}
