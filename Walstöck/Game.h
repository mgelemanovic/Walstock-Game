#ifndef WALSTOCK_GAME_H
#define WALSTOCK_GAME_H

#include "Window.h"
#include "Shader.h"
#include "Buffer.h"

class Game {
private:
	Window *window_;
	Shader *shader_;
	Buffer *data_;
public:
	Game();
	~Game();
	void gameLoop();
	virtual void input();
	virtual void update();
	virtual void render();
};

Game::Game() {
	window_ = new Window("Walstock", 1200, 675);
	shader_ = new Shader("vertex.glsl", "fragment.glsl");
	data_ = new Buffer();
}

Game::~Game() {
	delete data_;
	delete shader_;
	delete window_;
}

void Game::gameLoop() {
	while (!glfwWindowShouldClose(window_->get())) {
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		input();
		update();
		render();

		// Swap the screen buffers
		glfwSwapBuffers(window_->get());
	}
}

void Game::input() {
	while (pressedKeys.size() > 0) {
		int key = pressedKeys.back();
		pressedKeys.pop_back();
		std::cout << "Pressed key \"" << key << "\"" << std::endl;
		switch (key) {
		case 256:
			glfwSetWindowShouldClose(window_->get(), GL_TRUE);
			break;
		case '1':
			data_->addObject(5, 5);
			break;
		case '2':
			data_->addObject(-5, 5);
			break;
		case '3':
			data_->addObject(-1, -2);
			break;
		case '4':
			data_->addObject(-7, 3);
			break;
		}
	}
}

void Game::update() {
	data_->addObject(0, 0);
	data_->addObject(2, 0);
}

void Game::render() {
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	data_->drawBuffer();
}

#endif