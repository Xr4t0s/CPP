#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon {
	private:
		std::string _type;
	
	public:
		Weapon( std::string type );

		void	setType(std::string newType);
		const std::string&	getType( void ) const;

		~Weapon();
};

#endif 