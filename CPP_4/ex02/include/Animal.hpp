#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string _type;

	public:
		AAnimal();
		AAnimal( const AAnimal& copy );
		AAnimal&	operator=( AAnimal const& rhs );

		AAnimal( std::string name );
		virtual void	makeSound( void ) const = 0;

		std::string	getType( void ) const;

		virtual ~AAnimal();
};

#endif