#include "materias/Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice( const Ice& copy ) : AMateria("ice") {
	std::cout << "Ice copy constructor called." << std::endl;
	this->_type = copy._type;
}

Ice& Ice::operator=( const Ice& rhs ) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}


AMateria* Ice::clone() const {
	return new Ice(*this);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}