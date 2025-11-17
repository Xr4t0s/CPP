#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type;

	public:
		Animal();
		Animal( const Animal& copy );
		Animal&	operator=( Animal const& rhs );

		Animal( std::string name );
		void	makeSound( void );

		std::string	getType( void ) const;

		~Animal();
};

#endif