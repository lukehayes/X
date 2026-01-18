#ifndef X_GL_VERTEX_ATTIB_H
#define X_GL_VERTEX_ATTIB_H

#include "glad/glad.h"


namespace X::GL
{
class VertexAttribute
{
public:
	static constexpr int POSITION  = 0;
	static constexpr int COLOR     = 1;
	static constexpr int NORMAL    = 2;


	VertexAttribute(int vertex_position,int vertex_size, int vertex_stride, int vertex_offset)
		: vertex_position(vertex_position),
		  vertex_size(vertex_size),
		  vertex_stride(vertex_stride),
		  vertex_offset(vertex_offset)
	{}

	X::GL::VertexAttribute set()
	{
		glVertexAttribPointer(
			this->vertex_position,
			this->vertex_size,
			GL_FLOAT,
			GL_FALSE,
			sizeof(float) * this->vertex_stride,
			(void*)(sizeof(float) * this->vertex_offset)
		);

		glEnableVertexAttribArray(this->vertex_position);

		return *this;
	}

	int vertex_position;
	int vertex_size;
	int vertex_stride;
	int vertex_offset;

};

void SetVertexAttribute(int vertex_position,int vertex_size, int vertex_stride, int vertex_offset)
	{
		glVertexAttribPointer(
			vertex_position,
			vertex_size,
			GL_FLOAT,
			GL_FALSE,
			sizeof(float) * vertex_stride,
			(void*)(sizeof(float) * vertex_offset)
		);

		glEnableVertexAttribArray(vertex_position);
	}
}

#endif // X_GL_VERTEX_ATTIB_H
