#ifndef WALSTOCK_INPUT_H
#define WALSTOCK_INPUT_H

#include <GLFW\glfw3.h>
#include <vector>

std::vector<int> pressedKeys;

void InputManager(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (action == GLFW_PRESS)
		pressedKeys.push_back(key);
}

#endif
