#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>
// #include "character/ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria( const AMateria& copy );
		virtual AMateria&	operator=( const AMateria& rhs );
		
		AMateria(std::string const & type);
		// [...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		// virtual void use(ICharacter& target);
		
		virtual ~AMateria();
};



#endif