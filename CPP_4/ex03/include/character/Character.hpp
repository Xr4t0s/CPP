#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"
#include "materias/AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria*	_bag[4];

	public:
		Character();
		Character( const Character& copy );
		Character& operator=( const Character& rhs );
		
		Character( const std::string& name );
		const std::string& getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

		~Character();
};

#endif