#include "easyfind.hpp"

const char* NoOcurrenceFound::what() const throw() {
	return "No occurence found in this container";
}