#include "ClapTrap.hpp"

//////////////////////////////////////////////////////////////////////////////////////////

	ClapTrap::ClapTrap( std::string name ) :
		_name(name),
		_health(10),
		_stamina(10),
		_damage(0) {}

	ClapTrap::ClapTrap( const ClapTrap& copy ) {
		*this = copy;
	}

	ClapTrap& ClapTrap::operator=( ClapTrap const& rhs ) {
		(void)rhs;
		return *this;
	}

	ClapTrap::~ClapTrap() {}

//////////////////////////////////////////////////////////////////////////////////////////

	void	ClapTrap::attack( const std::string& target ) {
		
	}