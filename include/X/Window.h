#ifndef X_WINDOW_H
#define X_WINDOW_H

#include <SDL3/SDL.h>

namespace X
{

class Window
{
public:
	Window(const char* title, int width, int height);
	~Window();

	/**
	* Get the underlying window pointer.
	*
	* @return SDL_Window*
	*
	*/
	SDL_Window* getHandle() const;

private:
	const char* title;
	int width;
	int height;

	SDL_Window*   window;
    SDL_GLContext window_ctx;
};

}

#endif // !X_WINDOW_H
