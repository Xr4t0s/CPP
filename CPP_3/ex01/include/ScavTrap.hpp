#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& copy );
		ScavTrap& operator=( ScavTrap const& rhs );
		
		void	attack( const std::string& target );
		void	guardGate();

		~ScavTrap();
};

#endif