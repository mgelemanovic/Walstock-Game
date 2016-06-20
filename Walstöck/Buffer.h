#ifndef WALSTOCK_BUFFER_H
#define WALSTOCK_BUFFER_H

#include <GL\glew.h>
#include <GL\freeglut.h>

class Buffer {
public:
	GLuint VBO, VAO;
	Buffer() {
		GLfloat vertices[] = {
			-0.5f,  0.5f, 0.0f,		// Top Left 
			0.5f,  0.5f, 0.0f,		// Top Right
			-0.5f, -0.5f, 0.0f,		// Bottom Left
			0.5f, -0.5f, 0.0f		// Bottom Right
		};

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	~Buffer() {
		// Properly de-allocate all resources once they've outlived their purpose
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	}
};

#endif
