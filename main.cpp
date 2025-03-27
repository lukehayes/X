#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <GL/gl.h>
#include <iostream>

int main(int argc, char *argv[])
{
    // ------------------------------------------------------------------------
    // Set initial state here.

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    SDL_Window* window = SDL_CreateWindow("Title", 800,600, SDL_WINDOW_OPENGL);
    SDL_GLContext window_ctx = SDL_GL_CreateContext(window);


    if (!window) {

        std::cout << "Window Initialization Failed" << std::endl;
        std::cout << "Error:" << SDL_GetError() << std::endl;
    }

    if (!window_ctx) {

        std::cout << "Window Context Failed" << std::endl;
        std::cout << "Error:" << SDL_GetError() << std::endl;
    }


    // Test basic OPENGL works
    glClearColor(0,1,0,1);
    glClear(GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(window);

    SDL_Delay(3000);


    SDL_GL_DestroyContext(window_ctx);
    SDL_DestroyWindow(window);
}
