#ifndef X_GL_GLPROGRAM
#define X_GL_GLPROGRAM


#include "X/Math/GLM.h"
#include "X/GL/VertexBuffer.h"
#include "X/GL/Shader.h"

namespace X::GL
{
struct GLProgram
{
	GLProgram() {}
	glm::mat4 projection;
	glm::mat4 view;

	X::GL::Shader shader;
	X::GL::VertexBuffer buffer;

};

inline GLProgram GLProgramCreate()
{
	GLProgram program;


	return program;
}
}

#endif // X_GL_GLPROGRAM
