#include "Window.h"
#include "Shader.h"
#include "Input.h"
#include "Buffer.h"

int main() {
	Window main("Walstock", InputManager::handleInput);
	Shader s("vertex.glsl", "fragment.glsl");
	Buffer data;

	main.gameLoop();

	return 0;
}