#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria {
	
	public:
		Cure();
		Cure( const Cure& copy );
		Cure& operator=( const Cure& rhs );
		~Cure();
};

#endif