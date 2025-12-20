#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type) {
	std::cout << "Weapon Constructor called." << std::endl;
}

void	Weapon::setType( std::string newType ) {
	_type = newType;
}

const std::string&	Weapon::getType( void ) const {
	return _type;
}

Weapon::~Weapon() {
	std::cout << "Weapon Destructor called." << std::endl;
}