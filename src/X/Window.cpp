#include "X/Window.h"

#include <iostream>

namespace X
{

Window::Window(const char* title, int width, int height)
	:title(title), width(width), height(height)
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

	this->window = SDL_CreateWindow(title, width, height, SDL_WINDOW_OPENGL);
	this->window_ctx = SDL_GL_CreateContext(this->window);

	if (window == NULL) {

		// In the case that the window could not be made...
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
	}

	if (!window_ctx) {

		std::cout << "Window Context Failed" << std::endl;
		std::cout << "Error:" << SDL_GetError() << std::endl;
	}
}

SDL_Window*
Window::getHandle() const
{
	return this->window;
}

Window::~Window() {
	SDL_GL_DestroyContext(this->window_ctx);
	SDL_DestroyWindow(this->window);

	SDL_Quit();
}
}
