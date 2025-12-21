#include "Animal.hpp"

AAnimal::AAnimal() : _type("EMPTY") {
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& copy ) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=( AAnimal const& rhs ) {
	std::cout << "Animal assignation constructor called" << std::endl;
	(void)rhs;
	return *this;
}

// constructeur perso
AAnimal::AAnimal( std::string name ) : _type(name) {
	std::cout << "\033[32mAnimal personnal constructor called\033[0m" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "Animal destructor called" << std::endl;
}


// void	AAnimal::makeSound( void ) const {
// 	if (_type == "Cat") {
// 		std::cout << "Miaou !" << std::endl;
// 	} else if (_type == "Dog") {
// 		std::cout << "Wouf !" << std::endl;
// 	} else {
// 		std::cout << "Some sound..." << std::endl;
// 	}
// }

std::string	AAnimal::getType( void ) const {
	return _type;
}