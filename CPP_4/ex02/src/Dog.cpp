#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& copy ) : AAnimal(copy), _brain(new Brain(*copy._brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=( Dog const& rhs ) {
	std::cout << "Dog assignation constructor called" << std::endl;
	if (this != &rhs) {
		AAnimal::operator=(rhs);

		delete this->_brain;
		_brain = new Brain(*rhs._brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Brain*	Dog::getBrain() const {
	return _brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof!!" << std::endl;
}