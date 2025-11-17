#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& copy ) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = copy;
}

Dog& Dog::operator=( Dog const& rhs ) {
	std::cout << "Dog assignation constructor called" << std::endl;
	(void)rhs;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}