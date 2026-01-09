#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("EMPTY") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const& rhs ) {
	std::cout << "WrongAnimal assignation constructor called" << std::endl;
	(void)rhs;
	return *this;
}

// constructeur perso
WrongAnimal::WrongAnimal( std::string name ) : _type(name) {
	std::cout << "WrongAnimal personnal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}


void	WrongAnimal::makeSound( void ) const {
	std::cout << "Some sound..." << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return _type;
}