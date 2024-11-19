#include <iostream>

#include "src/graphics/Window.h"

int main()
{
	// hello, world
	using namespace self;
	using namespace graphics;
	
	Window window("Super Game Engine", 1366, 768);
	glClearColor(0.2f, 0.3f, 0.8f, 1.f);

	while (!window.Closed())
	{
		window.clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();

	}

	return 0;
}