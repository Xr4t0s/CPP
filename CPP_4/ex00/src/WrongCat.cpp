#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& copy ) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	
	WrongAnimal::operator=(copy);
}

WrongCat& WrongCat::operator=( WrongCat const& rhs ) {
	std::cout << "WrongCat assignation constructor called" << std::endl;
	
	if (this != &rhs) WrongAnimal::operator=(rhs);

	return *this;
}

WrongCat::~WrongCat() { // never called
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound( void ) const { // never called
	std::cout << "Wrong miaouu!!" << std::endl;
}