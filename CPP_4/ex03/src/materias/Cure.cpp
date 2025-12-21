#include "Cure.hpp"

Cure::Cure() : AMateria("ice") {
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure( const Cure& copy ) : AMateria("cure") {
	*this = copy;
}

Cure& Cure::operator=( const Cure& rhs ) {
	if (this != &rhs) {
		*this = rhs;
		return *this;
	}
	return *this;
}

Cure::~Cure() {}