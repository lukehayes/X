#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include "X/GL/VertexBuffer.h"
#include "glad/glad.h"

#include "X/GL/Shader.h"
#include "X/Math/GLM.h"
#include "X/GL/GLProgram.h"
#include "X/Model/Model.h"


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

    glm::vec4 color = glm::vec4{0.45,0.45,0.45,1.0};
    default_shader.setUniformVec4(color, "color");


    X::GL::GLProgram program = X::GL::GLProgramCreate();
    //program.projection = glm::perspective(45.0f, (float)WIN_HEIGHT / (float)WIN_HEIGHT, 0.1f, 100.f);
    //program.projection = glm::ortho(0.0f,0.0f,800.0f,600.0f,1.0f, 10.0f);

    // Centered 2D projection
    program.projection = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, 0.1f, 1000.0f);
    program.view = glm::mat4(1.0f);
    //program.view = glm::lookAt(
        //(glm::vec3){0,0,-10.0},
        //(glm::vec3){0,0, 0},
        //(glm::vec3){0,1,0}
    //);


    X::GL::VertexBuffer buffer;
    VertexBufferMake(&buffer);
    VertexBufferSetData(&buffer);

    program.buffer = buffer;
    program.shader = default_shader;

    float c = 0.0;

    Model::Model model({0.01,0,-3.0f});

    model.matrix = glm::translate(model.matrix, model.position);
    model.matrix = glm::rotate(model.matrix, glm::radians(model.rotAngle), model.rotation);


    while (isRunning) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }

        // Test basic OPENGL works
        float cv = 0.60;

        glClearColor(cv,cv,cv,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        c += 0.01;

        default_shader.use();

    model.matrix = glm::rotate(model.matrix, glm::radians(model.rotAngle), model.rotation);

        default_shader.SetUniformMat4(program.projection, "projection");
        default_shader.SetUniformMat4(program.view, "view");

        default_shader.SetUniformMat4(model.matrix, "model");
        default_shader.setUniformVec4(color, "color");
        glDrawArrays(GL_TRIANGLES,0,3);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DestroyContext(window_ctx);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
