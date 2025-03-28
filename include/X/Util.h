/**
* Utility helper functions.
*/
#ifndef X_UTIL_H
#define X_UTIL_H

#include <string>

namespace X {

/**
* Read a file into a string.
*
* @param const std::string& file    The name of the file to read.
*
* @return std::string
*/
std::string readFile(const std::string& file);

}

#endif // !X_UTIL_H
