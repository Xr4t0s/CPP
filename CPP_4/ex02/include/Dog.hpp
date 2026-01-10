#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain* _brain;

	public:
		Dog();
		Dog( const Dog& copy );
		Dog&	operator=( Dog const& rhs );

		void	makeSound( void ) const;
		Brain*	getBrain( void ) const;

		~Dog();
};

#endif