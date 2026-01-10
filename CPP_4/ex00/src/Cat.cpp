#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) : Animal(copy) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=( Cat const& rhs ) {
	std::cout << "Cat assignation constructor called" << std::endl;
	
	if (this != &rhs) Animal::operator=(rhs);

	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound( void ) const {
	std::cout << "Miaouu!!" << std::endl;
}