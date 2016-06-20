#include "Window.h"
#include "Shader.h"
#include "Input.h"

int main() {
	Window main("Walstock", InputManager::handleInput, 1200, 675);
	Shader s("vertex.glsl", "fragment.glsl");

	main.gameLoop();

	return 0;
}