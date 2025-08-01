#ifndef GL_VERTEXBUFFER_H
#define GL_VERTEXBUFFER_H

#include "glad/glad.h"
#include <vector>

namespace X::GL
{
constexpr std::size_t VTX_ATTRIB_POSITION  = 0;
constexpr std::size_t VTX_ATTRIB_COLOR     = 1;
constexpr std::size_t VTX_ATTRIB_TEXTURE   = 2;

class VertexBuffer
{
public:

	VertexBuffer();
	VertexBuffer(const VertexBuffer& rhs) = delete;
	VertexBuffer& operator=(const VertexBuffer& rhs) = delete;

	VertexBuffer(const VertexBuffer&& rhs);
	VertexBuffer& operator=(const VertexBuffer&& rhs);


	~VertexBuffer();

	static VertexBuffer Make(
		GLuint idx,
		GLuint sz,
		const std::vector<float>& data,
		const std::vector<unsigned int>& indices
	);

	void Create();
	void SetData();
	void Release();


	GLuint vertexBufferObject;
	GLuint indexBufferObject;
};
}


#endif // !GL_VERTEXBUFFER_H
