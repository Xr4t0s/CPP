#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;

	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal& copy );
		WrongAnimal&	operator=( WrongAnimal const& rhs );

		WrongAnimal( std::string name );
		void	makeSound( void ) const;

		std::string	getType( void ) const;

		virtual ~WrongAnimal();
};

#endif