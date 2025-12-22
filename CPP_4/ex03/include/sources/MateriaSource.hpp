#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "sources/IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:	
		AMateria*	_slots[4];

	public:
		MateriaSource();
		MateriaSource( const MateriaSource& copy );
		MateriaSource& operator=( const MateriaSource& rhs );

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

		~MateriaSource();
};

#endif