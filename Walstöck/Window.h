#ifndef WALSTOCK_WINDOW_H
#define WALSTOCK_WINDOW_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Input.h"

class Window {
private:
	GLFWwindow* window_;
	GLint width_, height_;
public:
	Window(const char* name, int width = 1920, int height = 1080);
	~Window();
	GLFWwindow* get();
	void changeResolution(int width, int height);
};

Window::Window(const char* name, int width, int height) :
	width_(width), height_(height) {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window_ = glfwCreateWindow(width_, height_, name, nullptr/*glfwGetPrimaryMonitor()*/, nullptr);
	glfwMakeContextCurrent(window_);

	glewExperimental = GL_TRUE;
	glewInit();

	glViewport(0, 0, width_, height_);

	glfwSetKeyCallback(window_, InputManager);
}

Window::~Window() {
	glfwTerminate();
}

GLFWwindow* Window::get() {
	return window_;
}

void Window::changeResolution(int width, int height) {}
		
#endif
