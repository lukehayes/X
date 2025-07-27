#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include "X/GL/VertexBuffer.h"
#include "glad/glad.h"

#include "X/GL/Shader.h"
#include "X/Math/GLM.h"
#include "X/Model/Model.h"
#include "X/Camera/Camera3D.h"
#include "X/Gfx/Renderer.h"

#include <vector>
#include <cstdlib>
#include <ctime>
#include <print>



int main(int argc, char *argv[])
{
    // ------------------------------------------------------------------------
    // Set initial state here.

    constexpr int WIN_MULT   = 4;
    constexpr int WIN_WIDTH  = 320 * WIN_MULT;
    constexpr int WIN_HEIGHT = 180 * WIN_MULT;

    bool isRunning           = true;

    if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
        std::cout << "Window Context Failed" << std::endl;
        std::cout << "Error:" << SDL_GetError() << std::endl;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

    SDL_Window* window       = SDL_CreateWindow("Title", WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_OPENGL);
    SDL_GLContext window_ctx = SDL_GL_CreateContext(window);

    SDL_GL_MakeCurrent(window, window_ctx);

    // INITIALIZE GLAD:
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        throw(std::string("Failed to initialize GLAD"));
    }

    if (window == NULL) {

        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    if (!window_ctx) {
        std::cout << "Window Context Failed" << std::endl;
        std::cout << "Error:" << SDL_GetError() << std::endl;
    }


    X::GL::Shader default_shader(
        "../assets/shaders/VSH-Camera3D.glsl",
        "../assets/shaders/FSH-Camera3D.glsl"
    );

    glm::vec4 color = glm::vec4{0.25,0.25,0.25,1.0};
    default_shader.setUniformVec4(color, "color");

    X::Gfx::Renderer renderer;


    X::Camera::Camera3D cam;
    X::GL::VertexBuffer buffer = X::GL::VertexBuffer::Make(
        0,
        3,
        {
        0.5f,  0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f
        },
        {
	 0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
        }
    );
    X::Model::Model model({0.01,0,-10.0f});
    model.color = {0.3,0.6,0.2,1.0};

    model.matrix = glm::translate(model.matrix, model.position);
    model.matrix = glm::scale(model.matrix, {1,1,1});

    std::vector<X::Model::Model> models;

    //std::srand( std::time({}) );

    for(int i = 0; i <= 10; i++)
    {
        constexpr int N = 4;
        float rx = -std::rand() % N + std::rand() % N;
        float ry = -std::rand() % N + std::rand() % N;
        float rz = -std::rand() % N + std::rand() % N;

        double rr = std::rand() % 100 / 100.0;
        double rg = std::rand() % 100 / 100.0;
        double rb = std::rand() % 100 / 100.0;
        double ra = std::rand() % 100 / 100.0;

        X::Model::Model model({(float)rx,(float)ry,-10 + rz});
        model.color = {0.2,0.22,rb,1.0};
        model.RotateX( std::rand() % 360 );

        models.push_back(model);
    }


    while (isRunning) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }

            if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key == SDLK_SPACE) {
                    std::println("SPace");
                }
            }
        }

        // Test basic OPENGL works
        float cv = 0.70;
        glClearColor(cv,cv,cv,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        cam.update(0.1);

        static float c = 0.0;
        c += 0.01;

        default_shader.use();
        default_shader.SetUniformMat4(cam.projection, "projection");
        default_shader.SetUniformMat4(cam.view, "view");

        renderer.Draw(0,0,0, default_shader);
        renderer.Draw(0,0,5, default_shader);
        renderer.Draw(5,0,0, default_shader);
        renderer.Draw(0,5,0, default_shader);

        for(auto m : models)
        {
            m.matrix = glm::translate(m.matrix, m.position);
            m.matrix = glm::scale(m.matrix, m.scale);


        renderer.Draw(
                m.position.x,
                m.position.y,
                m.position.z,
                default_shader);

            //default_shader.SetUniformMat4(m.matrix, "model");
            //default_shader.setUniformVec4(m.color, "color");
            //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        }





        SDL_GL_SwapWindow(window);

    }


    SDL_GL_DestroyContext(window_ctx);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
