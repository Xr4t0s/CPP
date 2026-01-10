#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( std::string name ) : _type(name) {
	std::cout << "Animal personnal constructor called" << std::endl;
}

Animal::Animal( const Animal& copy ) : _type("Animal") {
	(void)copy;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=( Animal const& rhs ) {
	std::cout << "Animal assignation constructor called" << std::endl;
	if (this != &rhs) {
		_type = rhs._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}


void	Animal::makeSound( void ) const {
	std::cout << "Some sound..." << std::endl;
}

std::string	Animal::getType( void ) const {
	return _type;
}