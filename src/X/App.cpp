#include "X/App.h"
#include <iostream>
#include "glad/glad.h"

namespace X
{

App::App(int width, int height)
	: width(width), height(height)
{
	this->Init();
}

void
App::Init()
{
	this->InitSDL();
	this->InitOpenGL();
	this->InitWindowContext();
}


void
App::InitSDL()
{
	if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
	{
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s\n", SDL_GetError());
		std::cout << "Window Context Failed" << std::endl;
		std::cout << "Error:" << SDL_GetError() << std::endl;
	}
}

void
App::InitOpenGL()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
}


void
App::InitWindowContext()
{
	this->window       = SDL_CreateWindow("Title", this->width, this->height, SDL_WINDOW_OPENGL);
	this->window_ctx = SDL_GL_CreateContext(window);

	SDL_GL_MakeCurrent(window, window_ctx);

	// INITIALIZE GLAD:
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		throw(std::string("Failed to initialize GLAD"));
	}

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
App::GetWindow()
{
	return this->window;
}

SDL_GLContext
App::GetContext()
{
	return this->window_ctx;
}

}


