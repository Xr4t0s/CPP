#include "Animal.hpp"

AAnimal::AAnimal() : _type("EMPTY") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& copy ) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=( AAnimal const& rhs ) {
	std::cout << "AAnimal assignation constructor called" << std::endl;
	(void)rhs;
	return *this;
}

// constructeur perso
AAnimal::AAnimal( std::string name ) : _type(name) {
	std::cout << "AAnimal personnal constructor called" << std::endl;
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