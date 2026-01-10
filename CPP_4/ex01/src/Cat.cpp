#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& copy ) : Animal(copy), _brain(new Brain(*copy._brain)) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=( Cat const& rhs ) {
	std::cout << "Cat assignation constructor called" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);

		delete this->_brain;
		_brain = new Brain(*rhs._brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Brain*	Cat::getBrain() const {
	return _brain;
}

void	Cat::makeSound( void ) const {
	std::cout << "Miaouu!!" << std::endl;
}