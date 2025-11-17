#include "Animal.hpp"

Animal::Animal() : _type("EMPTY") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( const Animal& copy ) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

Animal& Animal::operator=( Animal const& rhs ) {
	std::cout << "Animal assignation constructor called" << std::endl;
	(void)rhs;
	return *this;
}

// constructeur perso
Animal::Animal( std::string name ) : _type(name) {
	std::cout << "Animal personnal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}


void	Animal::makeSound( void ) {
	if (_type == "Cat") {
		std::cout << "Miaou !" << std::endl;
	} else if (_type == "Dog") {
		std::cout << "Wouf !" << std::endl;
	} else {
		std::cout << "Some sound..." << std::endl;
	}
}

std::string	Animal::getType( void ) const {
	return _type;
}