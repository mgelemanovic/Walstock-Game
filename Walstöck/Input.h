#ifndef WALSTOCK_INPUT_H
#define WALSTOCK_INPUT_H

#include <GLFW\glfw3.h>

class InputManager {
public:
	static void handleInput(GLFWwindow* window, int key, int scancode, int action, int mode) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
	}
};

#endif
