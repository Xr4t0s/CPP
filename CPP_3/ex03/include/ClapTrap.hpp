#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string	_name;
		int			_health;
		int			_stamina;
		int			_damage;
	
	public:
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap& copy );
		ClapTrap&	operator=( ClapTrap const& rhs );

		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );

		~ClapTrap();
		
};

#endif