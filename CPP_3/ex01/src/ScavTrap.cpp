#include "ScavTrap.hpp"

//////////////////////////////////////////////////////////////////////////////////////////

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	_health = 100;
	_stamina = 50;
	_damage = 20;
	std::cout << "ScavTrap default constructor called." << std::endl; 
}

ScavTrap::ScavTrap( const ScavTrap& copy ) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called !" << std::endl;
	*this = copy;
}

ScavTrap&	ScavTrap::operator=( ScavTrap const& rhs ) {
	(void)rhs;
	std::cout << "ScavTrap assignation constructor called !" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap default destructor called." << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in gateKeeper mode !" << std::endl;
}

void	ScavTrap::attack( const std::string& target ) {
	std::cout <<
		_name <<
		" attacks furiously "
		<< target <<
		" causing "
		<< _damage <<
		" mega damage points!"
	<< std::endl;
}
