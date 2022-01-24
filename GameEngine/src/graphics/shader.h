#pragma once

#include <GL/glew.h>
#include "../util/fileutils.h"

namespace bane {
	class Shader {
	private:
		GLuint m_ShaderID;

		const char* m_VertexPath;
		const char* m_FragmentPath;

		GLuint load();
	public:
		Shader(const char* vertexPath, const char* fragmentPath);
		~Shader();

		void enable() const;
		void disable() const;
	};
}