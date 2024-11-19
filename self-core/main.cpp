#include <iostream>

#include "src/graphics/Window.h"

int main()
{
	using namespace self;
	using namespace graphics;
	
	Window window("Super Game Engine", 1366, 768);
	glClearColor(0.2f, 0.3f, 0.8f, 1.f);

	unsigned int vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.Closed())
	{
		window.clear();
#if 0
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#endif
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();

	}

	return 0;
}