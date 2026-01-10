#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& copy ) : Animal(copy) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=( Dog const& rhs ) {
	std::cout << "Dog assignation constructor called" << std::endl;
	
	if (this != &rhs) Animal::operator=(rhs);
	
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound( void ) const {
	std::cout << "Woof!!" << std::endl;
}