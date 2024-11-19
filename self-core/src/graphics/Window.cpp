#include "Window.h"

namespace self
{
	namespace graphics
	{
		void windowResize(GLFWwindow* window, int width, int height);

		Window::Window(const char* title, int width, int height)
		{
			this->title = title; // title
			this->width = width; // width
			this->height = height; // height
			if (!this->init()) glfwTerminate();
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			glfwPollEvents();
			glfwSwapBuffers(this->window);
		}

		bool Window::Closed() const
		{
			return glfwWindowShouldClose(this->window) == 1;
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initialize GLFW\n";
				return false;
			}
			this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
			if (!this->window)
			{
				std::cout << "Failed to create GLFW Window\n";
				return false;
			}

			glfwMakeContextCurrent(this->window);
			glfwSetWindowSizeCallback(this->window, windowResize);
			return true;
		}

		void windowResize(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}

	}
}