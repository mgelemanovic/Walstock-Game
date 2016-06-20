#ifndef WALSTOCK_WINDOW_H
#define WALSTOCK_WINDOW_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>

class Window {
private:
	GLFWwindow* window_;
	GLint width_, height_;
public:
	Window(const char* name, GLFWkeyfun input, int width=1920, int height=1080):
		width_(width), height_(height)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		window_ = glfwCreateWindow(width_, height_, name, glfwGetPrimaryMonitor(), nullptr);
		glfwMakeContextCurrent(window_);

		glewExperimental = GL_TRUE;
		glewInit();

		glViewport(0, 0, width_, height_);

		glfwSetKeyCallback(window_, input);
	}
	~Window() {
		glfwTerminate();
	}
	void gameLoop() {
		while (!glfwWindowShouldClose(window_)) {
			// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
			glfwPollEvents();

			// Render
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

			// Swap the screen buffers
			glfwSwapBuffers(window_);
		}
	}
	void changeResolution(int width, int height) {}
};
		
#endif
