#include "DiamondTrap.hpp"

//////////////////////////////////////////////////////////////////////////////////////////

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), _name(name) {
	_health = 100;
	_stamina = 50;
	_damage = 30;
	std::cout << "DiamondTrap default constructor called." << std::endl; 
}

DiamondTrap::DiamondTrap( const DiamondTrap& copy ) : ClapTrap(copy) {
	std::cout << "DiamondTrap copy constructor called !" << std::endl;
	*this = copy;
}

DiamondTrap&	DiamondTrap::operator=( DiamondTrap const& rhs ) {
	(void)rhs;
	std::cout << "DiamondTrap assignation constructor called !" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap default destructor called." << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////

void	DiamondTrap::attack( const std::string& target ) {
	std::cout <<
		ClapTrap::_name <<
		" attacks furiously "
		<< target <<
		" causing "
		<< _damage <<
		" mega damage points!"
	<< std::endl;
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << "DiamondTrap name:\t" << _name << std::endl;
	std::cout << "ClapTrap name:\t\t" << ClapTrap::_name << std::endl;
}
