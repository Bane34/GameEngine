#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "../util/fileutils.h"

namespace bane {
	class Shader {
	private:
		GLuint m_ShaderID;

		const char* m_VertexPath;
		const char* m_FragmentPath;

		GLuint load();
		inline GLint getUniformLocation(const char* name) const { return glGetUniformLocation(m_ShaderID, name); }
	public:
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		inline GLuint& getProgram() { return m_ShaderID; }

		void enable() const;
		void disable() const;
		
		// UNIFORMS //
		void setUniform1f(const char* name, float n) const;
		void setUniform1i(const char* name, int n) const;

		void setUniformVec2f(const char* name, const glm::fvec2& vec2) const;
		void setUniformVec3f(const char* name, const glm::fvec3& vec3) const;
		void setUniformVec4f(const char* name, const glm::fvec4& vec4) const;

		void setUniformMat4(const char* name, const glm::mat4& matrix) const;
		
	};
}