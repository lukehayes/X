#include "X/GL/BufferData.h"

namespace X::GL
{
BufferData::BufferData(std::uint8_t attrib_position, std::vector<float>& verticies, const std::vector<unsigned int>& indicies)
	: verticies(verticies),
	  indicies(indicies)
{
}

BufferData::~BufferData()
{
}

}

