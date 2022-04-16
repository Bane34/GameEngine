#include "shader.h"	

namespace bane {
	Shader::Shader(const char* vertexPath, const char* fragmentPath) {
		m_VertexPath = vertexPath;
		m_FragmentPath = fragmentPath;

		m_ShaderID = load();
	}

	Shader::~Shader() {
		glDeleteProgram(m_ShaderID);
	}

	GLuint Shader::load() {
		int success;
		char infoLog[512];

		// LOAD SHADERS CODE //
		std::string vertexStringSource = readFile("src/shaders/vertexShader.glsl");
		std::string fragmentStringSource = readFile("src/shaders/fragmentShader.glsl");
		const char* vertexSource = vertexStringSource.c_str();
		const char* fragmentSource = fragmentStringSource.c_str();

		// VERTEX SHADER //
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShaderID, 1, &vertexSource, NULL);
		glCompileShader(vertexShaderID);
		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
		}

		// FRAGMENT SHADER //
		GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShaderID, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShaderID);
		glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << "\n";
		}

		// PROGRAM //
		GLuint shaderProgramID;
		shaderProgramID = glCreateProgram();
		glAttachShader(shaderProgramID, vertexShaderID);
		glAttachShader(shaderProgramID, fragmentShaderID);
		glLinkProgram(shaderProgramID);
		glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgramID, 512, NULL, infoLog);
			std::cout << "ERROR::PROGRAM::SHADER::LINKING_FAILED\n" << infoLog << "\n";
		}

		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		return shaderProgramID;
	}

	void Shader::enable() const {
		glUseProgram(m_ShaderID);
	}

	void Shader::disable() const {
		glUseProgram(0);
	}

	void Shader::setUniform1f(const char* name, float n) const {
		glUniform1f(getUniformLocation(name), n);
	}

	void Shader::setUniform1i(const char* name, int n) const {
		glUniform1i(getUniformLocation(name), n);
	}

	void Shader::setUniformVec2f(const char* name, const glm::fvec2& vec2) const {
		glUniform2f(getUniformLocation(name), vec2.x, vec2.y);
	}

	void Shader::setUniformVec3f(const char* name, const glm::fvec3& vec3) const {
		glUniform3f(getUniformLocation(name), vec3.x, vec3.y, vec3.z);
	}

	void Shader::setUniformVec4f(const char* name, const glm::fvec4& vec4) const {
		glUniform4f(getUniformLocation(name), vec4.x, vec4.y, vec4.z, vec4.w);
	}

	void Shader::setUniformMat4(const char* name, const glm::mat4& mat4) const {
		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &mat4[0][0]);
	}
}