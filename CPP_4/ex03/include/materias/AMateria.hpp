#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>
#include "character/ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria( const AMateria& copy );
		virtual AMateria&	operator=( const AMateria& rhs );
		
		AMateria(std::string const & type);
		const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
		
		virtual ~AMateria();
};



#endif