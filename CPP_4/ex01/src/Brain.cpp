#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( const Brain& copy ) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = copy._ideas[i];
	}
}

Brain& Brain::operator=( const Brain& rhs ) {
	std::cout << "Brain assignation constructor called" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}

const std::string& Brain::getIdea( int index ) const {
	return _ideas[index];
}

void	Brain::setIdea( int index, const std::string& idea ) {
	_ideas[index] = idea;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
