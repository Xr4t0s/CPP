#include "errors/Errors.hpp"

static const std::string messages[] = {
	ERR "[ERROR] " RST "Bad file",
	ERR "[ERROR] " RST "Bad header",
	ERR "[ERROR] " RST "Bad date",
	ERR "[ERROR] " RST "Bad value",
};

FileError::FileError(FileErrors reason) {
	_error = messages[reason];
	_error.append("\n");
}

FileError::FileError(FileErrors reason, std::string intel) {
	_error = messages[reason];
	_error.append("\n\tTraceback => ");
	_error.append(intel);
}

FileError::~FileError() throw() {}

const char* FileError::what() const throw() {
	return _error.c_str();
}

const char* UsageError::what() const throw() {
	return "Usage: ./btc attachments/input.txt"; 
}

std::string	buildErr(FileErrors errorType, std::string line, uint nLine) {
	std::string intel = "at line ";
	std::ostringstream oss;
	oss << nLine;
	oss << ": ";
	intel.append(oss.str());
	intel.append(line);
	throw FileError(errorType, intel);
}
std::string	buildErr(FileErrors errorType, std::string line, uint nLine, std::string intel) {
	intel.append(" at line ");
	std::ostringstream oss;
	oss << nLine;
	oss << ": ";
	intel.append(oss.str());
	intel.append(line);
	throw FileError(errorType, intel);
}
