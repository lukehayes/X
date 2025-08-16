#ifndef X_APP_H
#define X_APP_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_timer.h>

namespace X
{

class App
{
public:
	App(int width, int height);

	void Init();

	SDL_Window* GetWindow();
	SDL_GLContext GetContext();

private:
	void InitSDL();
	void InitOpenGL();
	void InitWindowContext();

private:
	size_t width;
	size_t height;
	SDL_Window* window;
	SDL_GLContext window_ctx;

};


}

#endif // !X_APP_H
