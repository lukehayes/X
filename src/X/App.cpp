#include "X/App.h"


namespace X
{
App::App(const char* title, int width, int height)
	:window(title, width, height)
{

}

X::Window
App::getWindow() const { return this->window; }

App::~App() {
	SDL_Quit();
}
}
