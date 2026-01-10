#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal( std::string name ) : _type(name) {
	std::cout << "AAnimal personnal constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& copy ) : _type("AAnimal") {
	(void)copy;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=( AAnimal const& rhs ) {
	std::cout << "AAnimal assignation constructor called" << std::endl;
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}


void	AAnimal::makeSound( void ) const {
	std::cout << "Some sound..." << std::endl;
}

std::string	AAnimal::getType( void ) const {
	return _type;
}