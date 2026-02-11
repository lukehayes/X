#ifndef X_GL_VERTEX_ATTRIBUTE_H
#define X_GL_VERTEX_ATTRIBUTE_H

#include "glad/glad.h"

namespace X::GL
{
	void SetVertexAttribute(int position, int size, int stride, int pointer )
	{
		glVertexAttribPointer(position,size,GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(sizeof(float) * pointer));
		glEnableVertexAttribArray(position);
	}
}

#endif // X_GL_VERTEX_ATTRIBUTE_H
