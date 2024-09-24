#include "XX/System/Window.h"
#include "glad/glad.h"
#include <string>
#include <SDL2/SDL.h>

namespace XX::System
{
Window::Window(size_t width, size_t height, std::string title)
{
	this->init(width, height,title);
}

void
Window::init(size_t width, size_t height, std::string title)
{

	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		fprintf(stderr, "ERROR: %s\n", SDL_GetError());
	}

	SDL_GL_LoadLibrary(NULL);

	// Request an OpenGL 4.6 context (should be core)
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	// Also request a depth buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	this->window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width, height,
	SDL_WINDOW_OPENGL);

	this->context = SDL_GL_CreateContext(this->window);

	SDL_GL_MakeCurrent(this->window,
	this->context);

	// Check OpenGL properties
	printf("OpenGL loaded\n");
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	printf("Vendor:   %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version:  %s\n", glGetString(GL_VERSION));

}

Window::~Window() 
{
	SDL_GL_DeleteContext(this->context);
	SDL_DestroyWindow(this->window);
}
}
