#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal( std::string name );
		Animal( const Animal& copy );
		Animal&	operator=( Animal const& rhs );

		virtual void	makeSound( void ) const;

		std::string	getType( void ) const;

		virtual ~Animal();
};

#endif