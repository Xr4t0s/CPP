#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

#include "Brain.hpp"

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal( std::string name );
		AAnimal( const AAnimal& copy );
		AAnimal&	operator=( AAnimal const& rhs );

		virtual void	makeSound( void ) const = 0;

		std::string	getType( void ) const;

		virtual ~AAnimal();
};

#endif