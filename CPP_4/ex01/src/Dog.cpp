#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& copy ) : Animal("Dog") {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*copy._brain);
}

Dog& Dog::operator=( Dog const& rhs ) {
	std::cout << "Dog assignation constructor called" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);

		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof!!" << std::endl;
}