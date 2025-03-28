#ifndef X_IO_H

#include <string>

namespace X::IO
{

/**
* Read the contents of a file into a std::string.
*
* @param const std::string& file    The file to read from.
*
* @return std::string& file    The contents of the file.
*/
std::string readFile(const std::string& file);

}


#endif // !X_IO_H
