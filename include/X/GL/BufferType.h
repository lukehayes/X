#ifndef X_GL_BUFFERTYPE
#define X_GL_BUFFERTYPE

#include "glad/glad.h"

/**
* Wrapper for OpenGL buffer types
*/
namespace X::GL
{
	enum BufferType
	{
		ARRAY_BUFFER = GL_ARRAY_BUFFER,
		ELEMENT_BUFFER = GL_ELEMENT_ARRAY_BUFFER
	};
}
#endif // !X_GL_BUFFERTYPE
