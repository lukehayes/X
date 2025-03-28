#include "X/Util.h"

#include <string>
#include <fstream>

namespace X {

std::string readFile(const std::string& file)
{
	std::string contents;
	std::fstream stream;

	stream.open(file);

	while (!stream.eof())
	{
		contents += stream.get();
	}

	stream.close();

	return contents;
}
}

