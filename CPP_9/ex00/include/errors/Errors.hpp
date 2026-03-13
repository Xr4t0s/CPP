#ifndef __ERRORS_HPP__
#define __ERRORS_HPP__

#include <iostream>
#include <sstream>

#define ERR "\033[1;31m"
#define RST "\033[0m"

typedef unsigned int uint;

typedef enum {
	BAD_FILE,
	BAD_HEADER,
	BAD_DATE,
	BAD_VALUE,
} FileErrors;

struct FileError : std::exception {
	private:
	std::string _error;
	
	public:	
	FileError(FileErrors reason);
	FileError(FileErrors reason, std::string intel);
	const char* what() const throw();
	~FileError() throw();
};

struct UsageError : std::exception {
	public:
		const char* what() const throw(); 
};

std::string	buildErr(FileErrors errorType, std::string line, uint nLine);
std::string	buildErr(FileErrors errorType, std::string line, uint nLine, std::string intel);

#endif