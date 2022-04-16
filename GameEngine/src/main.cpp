#include "graphics/window.h"
#include "graphics/shader.h"
#include "util/fileutils.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexbuffer.h"
#include "graphics/buffers/vertexarray.h"


#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include <memory>

using namespace bane;

// TODO:
// -Implementar sistema de buffers
// -Renderer como dios manda
// -Limpiar el codigo <- XD
// -Hacer un sistema de capas para poder integrar ImGui correctamente
// -Introducir un build system (premake o Cmake ?)

int main() {
	Window window("Title", 800, 600);

	GLfloat vertices[] = {
		0.0f, 0.0f, 0.0f,
		0.5f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	GLushort indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};
	
	VertexArray sprite1;
	IndexBuffer ibo(indices, 6);
	sprite1.addBuffer(new Buffer(vertices, 3 * 4, 3), 0);
	sprite1.addBuffer(new Buffer(colors, 4 * 4, 3), 1);

	Shader shader("src/shaders/vertexShader.glsl", "src/shaders/fragmentShader.glsl");
	shader.enable();

	glm::mat4 orthographic = glm::ortho(-10.0f, 10.0f, -7.5f, 7.5f, -1.0f, 1.0f);
	shader.setUniformMat4("pr_matrix", orthographic);

	while (!window.closed()) {
		window.update();
		window.clear();

		sprite1.bind();
		ibo.bind();

		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);

		window.render();
	}

	shader.disable();
	sprite1.unbind();
	ibo.unbind();
}