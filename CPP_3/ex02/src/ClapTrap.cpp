#include "ClapTrap.hpp"

//////////////////////////////////////////////////////////////////////////////////////////

	ClapTrap::ClapTrap( std::string name ) :
		_name(name),
		_health(10),
		_stamina(10),
		_damage(0) 
	{
		std::cout << "Default constructor called !" << std::endl;
	}

	ClapTrap::ClapTrap( const ClapTrap& copy ) {
		std::cout << "Copy constructor called !" << std::endl;
		*this = copy;
	}

	ClapTrap& ClapTrap::operator=( ClapTrap const& rhs ) {
		std::cout << "Assignation constructor called !" << std::endl;
		(void)rhs;
		return *this;
	}

	ClapTrap::~ClapTrap() {
		std::cout << "Default destructor called !" << std::endl;
	}

//////////////////////////////////////////////////////////////////////////////////////////

	void	ClapTrap::attack( const std::string& target ) {
		std::cout <<
			_name <<
			" attacks "
			<< target <<
			" causing "
			<< _damage <<
			" damage points!"
		<< std::endl;
	}

	void	ClapTrap::takeDamage( unsigned int amount ) {
		_health -= amount;
		if (_health < 0) _health = 0;
	
		std::cout <<
			_name <<
			" took "
			<< amount <<
			" damage points."
		<< std::endl;
	}
	
	void	ClapTrap::beRepaired( unsigned int amount ) {
		_health += amount;
		
		std::cout <<
			_name <<
			" gained "
			<< amount <<
			" health points."
		<< std::endl;
	}