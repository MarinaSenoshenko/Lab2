#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_
#include <exception>
#include <string>
#include <system_error>

class FileException : public std::runtime_error {
public:
	FileException(std::string fileName);
};

#endif
