#include "FragTrap.hpp"

//////////////////////////////////////////////////////////////////////////////////////////

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	_health = 100;
	_stamina = 50;
	_damage = 20;
	std::cout << "FragTrap default constructor called." << std::endl; 
}

FragTrap::FragTrap( const FragTrap& copy ) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called !" << std::endl;
	*this = copy;
}

FragTrap&	FragTrap::operator=( FragTrap const& rhs ) {
	(void)rhs;
	std::cout << "FragTrap assignation constructor called !" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap default destructor called." << std::endl;
}

//////////////////////////////////////////////////////////////////////////////////////////

void	FragTrap::highFivesGuys( void ) const {
	std::cout << "High five guys !" << std::endl;
}
