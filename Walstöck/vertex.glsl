#version 330 core

layout (location = 0) in vec3 position;

void main() {
	gl_Position = vec4(position.x / 16, position.y / 9, position.z, 1.0);
}
