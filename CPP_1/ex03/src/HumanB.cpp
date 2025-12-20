#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name), _weapon(NULL) {
	std::cout << "HumanB Constructor called." << std::endl;
}

void	HumanB::attack( void ) const {
	if ( _weapon )
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " has no weapons! " << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon ) {
	_weapon = &weapon;
}

HumanB::~HumanB() {
	std::cout << "HumanB Destructor called." << std::endl;
}