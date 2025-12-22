#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "materias/AMateria.hpp"

class Cure : public AMateria {
	
	public:
		Cure();
		Cure( const Cure& copy );
		Cure& operator=( const Cure& rhs );
		
		AMateria* clone() const;
		void use(ICharacter& target);

		~Cure();
};

#endif