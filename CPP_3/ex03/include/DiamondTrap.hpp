#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap {
	private:
		std::string _name;

	public:
		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& copy );
		DiamondTrap& operator=( DiamondTrap const& rhs );
		
		void	attack( const std::string& target );
		void	whoAmI( void );
		
		~DiamondTrap();
};

#endif