
#include <SDL3/SDL_main.h>
#include <GL/gl.h>

#include "X/App.h"

int main(int argc, char *argv[])
{
    // ------------------------------------------------------------------------
    // Set initial state here.

    X::App app("Test", 200,200);

    bool isRunning = true;

    while (isRunning) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }
        }

        // Test basic OPENGL works
        glClearColor(0,0,1,1);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(app.getWindow().getHandle());
    }
}
