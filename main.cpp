#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>
#include "glad/glad.h"

#include "X/GL/Shader.h"

int main(int argc, char *argv[])
{
    // ------------------------------------------------------------------------
    // Set initial state here.

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

    SDL_Window* window       = SDL_CreateWindow("Title", 800,600, SDL_WINDOW_OPENGL);
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


    //X::GL::Shader default_shader(
        //"VSH-Default.glsl",
        //"FSH-Default.glsl"
    //);


    while (isRunning) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }

        // Test basic OPENGL works
        float cv = 0.25;
        glClearColor(cv,cv,cv,1);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DestroyContext(window_ctx);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
