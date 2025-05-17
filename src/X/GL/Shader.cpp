#include "X/GL/Shader.h"

namespace X::GL
{
	Shader::Shader(const char* vsh, const char* fsh) {}

	Shader::Shader(
			const std::string& vsh,
			const std::string& fsh
		) {}

	Shader::Shader(const Shader& rhs) {}
	Shader::Shader(const Shader&& rhs) {}

	Shader&
	Shader::operator=(Shader& rhs)  { return *this; }

	Shader&
	Shader::operator=(Shader&& rhs) { return *this; }

	Shader::~Shader() {}
}
