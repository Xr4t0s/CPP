#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) : Animal() {
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
}