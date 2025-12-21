#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat( const Cat& copy );
		Cat&	operator=( Cat const& rhs );

		virtual	void	makeSound( void ) const;

		virtual ~Cat();
};

#endif