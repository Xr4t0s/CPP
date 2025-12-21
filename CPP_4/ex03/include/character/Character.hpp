#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character();
		Character( const Character& copy );
		Character& operator=( const Character& rhs );
		
		~Character();
};

#endif