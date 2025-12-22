#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "materias/AMateria.hpp"

class Ice : public AMateria {
	
	public:
		Ice();
		Ice( const Ice& copy );
		Ice& operator=( const Ice& rhs );

		AMateria* clone() const;
		// void use(ICharacter& target);

		~Ice();
};

#endif