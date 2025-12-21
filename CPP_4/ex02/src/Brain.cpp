#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;  
}

Brain::Brain( const Brain& copy ) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain& Brain::operator=( const Brain& rhs ) {
	std::cout << "Brain assignation constructor called" << std::endl;
	(void)rhs;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
