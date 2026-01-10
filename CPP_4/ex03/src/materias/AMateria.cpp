#include "materias/AMateria.hpp"
#include "character/ICharacter.hpp"

AMateria::AMateria( void ) : _type("") {
	std::cout << "Materia default constructor called" << std::endl;
};

AMateria::AMateria( const AMateria& copy ) : _type(copy._type) {
	std::cout << "Materia copy constructor called" << std::endl;
};

AMateria::AMateria( const std::string& type ) : _type(type) {
	std::cout << "Materia type constructor called" << std::endl;
};

AMateria&	AMateria::operator=( const AMateria& rhs ) {
	if (this != &rhs) _type = rhs._type;
	
	return *this;
}

AMateria::~AMateria() {
	std::cout << "Materia destructor called" << std::endl;
}

void	AMateria::use(ICharacter& target) {
	(void)target;
}

const std::string& AMateria::getType( void ) const {
	return _type;
}



