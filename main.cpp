#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <iostream>

int main(int argc, char *argv[])
{
    // ------------------------------------------------------------------------
    // Set initial state here.

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    SDL_Window* window = SDL_CreateWindow("Title", 800,600, SDL_WINDOW_OPENGL);

    if (!window) {

        std::cout << "Window Initialization Failed" << std::endl;
        std::cout << "Error:" << SDL_GetError() << std::endl;
    }

    SDL_DestroyWindow(window);
}
