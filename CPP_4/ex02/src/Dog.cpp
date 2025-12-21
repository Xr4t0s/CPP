#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& copy ) : AAnimal() {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=( Dog const& rhs ) {
	std::cout << "Dog assignation constructor called" << std::endl;
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		*_brain = *rhs._brain;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}

void	Dog::makeSound( void ) const {
	std::cout << "Wouf !" << std::endl;
}