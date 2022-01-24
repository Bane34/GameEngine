#include "graphics/window.h"
#include "graphics/shader.h"
#include "util/fileutils.h"	

using namespace bane;

int main() {
	Window window("Title", 800, 600);

	GLfloat vertices[] = {
		 0.5f,	 0.5f, 0.0f,
		 0.5f,	-0.5f, 0.0f,
		-0.5f,  -0.5f, 0.0f,
		-0.5f,   0.5f, 0.0f
	};

	GLuint indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	GLuint VBO; // vertex buffer object
	glGenBuffers(1, &VBO);

	GLuint VAO; // vertex array object
	glGenVertexArrays(1, &VAO);

	GLuint EBO; // element buffer object
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	Shader shader("src/shaders/vertexShader.glsl", "src/shaders/fragmentShader.glsl");
	shader.enable();

	while (!window.closed()) {
		window.update();
		window.clear();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		window.render();
	}

	shader.disable();
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}