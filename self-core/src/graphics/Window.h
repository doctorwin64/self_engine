#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>


namespace self
{
	namespace graphics
	{
		class Window
		{
		private:
			const char* title;
			int width, height;
			GLFWwindow* window;
			bool closed;
		public:
			Window(const char* title, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool Closed() const;

			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }

		private:
			bool init();
		};
	}
}