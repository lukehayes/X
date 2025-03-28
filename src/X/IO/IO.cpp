#include "X/IO/IO.h"

#include <fstream>
#include <iostream>


namespace X::IO
{

std::string readFile(const std::string& file)
{
	std::ifstream stream(file);
	std::string   contents;

	while(stream)
	{
		//char c = stream.get();
		//std::cout << (char)c << std::endl;

		stream >> contents;
	}


	return contents;
}

}
