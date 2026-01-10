#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string name ) : _type(name) {
	std::cout << "WrongAnimal personnal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy ) : _type("WrongAnimal") {
	(void)copy;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const& rhs ) {
	std::cout << "WrongAnimal assignation constructor called" << std::endl;
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}


void	WrongAnimal::makeSound( void ) const {
	std::cout << "Some wrong sound..." << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return _type;
}