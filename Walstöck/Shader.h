#ifndef WALSTOCK_SHADER_H
#define WALSTOCK_SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

class Shader {
private:
	GLuint program_;
	GLint success_;
	GLchar infoLog_[512];
private:
	GLuint getShader(const GLchar* path, GLenum type) {
		using namespace std;
		string code;
		ifstream file;
		file.exceptions(ifstream::badbit);
		try {
			file.open(path);
			stringstream stream;
			stream << file.rdbuf();
			file.close();
			code = stream.str();
		}
		catch (ifstream::failure e) {
			cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
		}

		const GLchar* shaderCode = code.c_str();
		GLuint shader = glCreateShader(type);
		glShaderSource(shader, 1, &shaderCode, NULL);
		glCompileShader(shader);

		// Print compile errors if any
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success_);
		if (!success_)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog_);
			cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog_ << endl;
		};

		return shader;
	}
public:
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath) :
		program_(glCreateProgram())
	{
		GLuint vertex(getShader(vertexPath, GL_VERTEX_SHADER));
		GLuint fragment(getShader(fragmentPath, GL_FRAGMENT_SHADER));

		glAttachShader(program_, vertex);
		glAttachShader(program_, fragment);
		glLinkProgram(program_);

		// Print linking errors if any
		glGetProgramiv(program_, GL_LINK_STATUS, &success_);
		if (!success_)
		{
			glGetProgramInfoLog(program_, 512, NULL, infoLog_);
			std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog_ << std::endl;
		}

		// Delete the shaders as they're linked into our program now and no longer necessery
		glDeleteShader(vertex);
		glDeleteShader(fragment);

		glUseProgram(program_);
	}
};

#endif
