#include "glad/glad.h"

namespace X::GL
{
	void SetVertexAttribute(int position, int size, int stride, int pointer )
	{
		glVertexAttribPointer(position,size,GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(sizeof(float) * pointer));
		glEnableVertexAttribArray(position);
	}
}
