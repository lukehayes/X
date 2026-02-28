#include "glad/glad.h"
#include <vector>

namespace X::GL
{
	class RectMesh
	{
public:
		RectMesh()
		{
			glGenVertexArrays(1, &this->vao);
			glGenBuffers(1, &this->vbo);
			glGenBuffers(1, &this->ibo);
		}

		void BindVertexArray()
		{
			glBindVertexArray(this->vao);
		}

		void SetArrayBufferData(const std::vector<float> &data)
		{
			glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
			glBufferData(
				GL_ARRAY_BUFFER,
				sizeof(data.at(0)) * data.size(),
				data.data(),
				GL_STATIC_DRAW
			);
		}

		void SetElementBufferData(const std::vector<unsigned int> &data)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
			glBufferData(
				GL_ELEMENT_ARRAY_BUFFER,
				sizeof(data.at(0)) * data.size(),
				data.data(),
				GL_STATIC_DRAW
			);
		}

		void SetAttribPointer(int position, int size, int stride, int pointer)
		{
			glVertexAttribPointer(
				position, 
				size,
				GL_FLOAT,
				GL_FALSE,
				sizeof(float) * stride,
				(void*)(sizeof(float) * pointer)
			);
			glEnableVertexAttribArray(position);
		}



	private:
		GLuint vao;
		GLuint vbo;
		GLuint ibo;
	};
}
