#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap( std::string name );
		FragTrap( const FragTrap& copy );
		FragTrap& operator=( FragTrap const& rhs );

		void	highFivesGuys( void ) const;

		~FragTrap();
};

#endif