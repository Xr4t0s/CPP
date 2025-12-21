#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) : AAnimal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=( Cat const& rhs ) {
	std::cout << "Cat assignation constructor called" << std::endl;
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		*_brain = *rhs._brain;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	this->_brain = NULL;
}

void	Cat::makeSound( void ) const {
	std::cout << "Miaou !" << std::endl;
}