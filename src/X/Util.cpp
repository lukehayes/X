#include "X/Util.h"

#include <string>
#include <fstream>
#include <filesystem>

namespace X {

std::string readFile(const std::string& file)
{
	if (!std::filesystem::exists(file)) return "FILE NOT FOUND";

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

