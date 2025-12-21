#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) : AAnimal() {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = copy;
}

Cat& Cat::operator=( Cat const& rhs ) {
	std::cout << "Cat assignation constructor called" << std::endl;
	(void)rhs;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound( void ) const {
	std::cout << "Miaouu!!" << std::endl;
}