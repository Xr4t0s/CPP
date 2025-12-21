#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice( const Ice& copy ) : AMateria("ice") {
	*this = copy;
}

Ice& Ice::operator=( const Ice& rhs ) {
	if (this != &rhs) {
		*this = rhs;
		return *this;
	}
	return *this;
}

Ice::~Ice() {}