#ifndef X_GL_SHADERTYPE
#define X_GL_SHADERTYPE

#include "glad/glad.h"

/**
* Wrapper for OpenGL shader types
*/
namespace X::GL
{
	enum ShaderType
	{
		VERTEX = GL_VERTEX_SHADER,
		FRAGMENT = GL_FRAGMENT_SHADER
	};
}

#endif // !X_GL_SHADERTYPE
