#ifndef X_GL_BUFFERDATA_H
#define X_GL_BUFFERDATA_H

#include <vector>
#include <cstdint>

namespace X::GL
{
class BufferData {
public:
	BufferData(std::uint8_t attrib_position, std::vector<float>& verticies, const std::vector<unsigned int>& indicies);
	BufferData(const BufferData &) = delete;
	BufferData& operator=(const BufferData &) = delete;

	BufferData(BufferData &&) = default;
	BufferData& operator=(BufferData &&) = default;
	~BufferData();

	inline std::vector<float> GetVerticies() { return this->verticies; }
	inline std::vector<unsigned int> GetIndicies() { return this->indicies; }
	inline int GetVertexCount() { return this->verticies.size(); }
	inline int GetIndexCount() { return this->indicies.size(); }

private:
	std::vector<float> verticies;
	std::vector<unsigned int> indicies;

};

BufferData::BufferData(std::uint8_t attrib_position, std::vector<float>& verticies, const std::vector<unsigned int>& indicies)
	: verticies(verticies),
	  indicies(indicies)
{
}

BufferData::~BufferData() 
{
}

}


#endif //X/GL_BUFFERDATA_H
