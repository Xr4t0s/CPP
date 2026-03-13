#include "errors/Errors.hpp"

const char* FileError::what() const throw() {
	return "File Error"; 
}

const char* UsageError::what() const throw() {
	return "Usage: ..."; 
}
