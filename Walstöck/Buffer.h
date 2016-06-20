#ifndef WALSTOCK_BUFFER_H
#define WALSTOCK_BUFFER_H

#include <GL\glew.h>
#include <GL\freeglut.h>

#include <vector>

class Buffer {
	GLuint VBO, VAO;
	std::vector<GLfloat> vertices;
	GLuint size;
public:
	Buffer();
	~Buffer();
	void addObject(int x, int y);
	void drawBuffer();
};

Buffer::Buffer() {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
}

Buffer::~Buffer() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Buffer::addObject(int x, int y) {
	GLfloat factorX[] = { 1, 1, -1, 1, -1, -1 };
	GLfloat factorY[] = { 1, -1, 1, -1, -1, 1 };

	for (int i = 0; i < 6; ++i) {
		vertices.push_back(x + 0.5f * factorX[i]);
		vertices.push_back(y + 0.5f * factorY[i]);
		vertices.push_back(0.0f);
	}

	++size;
}

void Buffer::drawBuffer() {
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glDrawArrays(GL_TRIANGLES, 0, 6 * size);
	glBindVertexArray(0);
}

#endif
