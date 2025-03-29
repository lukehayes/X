#ifndef X_APP_H
#define X_APP_H

#include "X/Window.h"

namespace X {

class App
{
public:
	App(const char* title, int width, int height);
	~App();

	X::Window getWindow() const;

private:

	X::Window window;


};
}


#endif // !X_APP_H
