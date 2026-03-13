#ifndef __ERRORS_HPP__
#define __ERRORS_HPP__

#include <iostream>

struct UsageError : std::exception {
	public:
		const char* what() const throw(); 
};

struct FileError : std::exception {
	public:
		const char* what() const throw(); 
};

#endif