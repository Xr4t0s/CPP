#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal( std::string name );
		AAnimal( const AAnimal& copy );
		AAnimal&	operator=( AAnimal const& rhs );

		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;

		virtual ~AAnimal();
};

#endif