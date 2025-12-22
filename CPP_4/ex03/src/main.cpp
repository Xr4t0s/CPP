#include "materias/Ice.hpp"
#include "materias/Cure.hpp"

int main() {
	AMateria*	ice = new Ice();
	AMateria*	cure = new Cure();

	std::cout << std::endl;
	std::cout << ice->getType() << std::endl;
	std::cout << cure->getType() << std::endl;
	std::cout << std::endl;

	AMateria* new_ice = ice->clone();
	AMateria* new_cure = cure->clone();
	
	std::cout << "Addr of *ice -> " << ice << "\nAddr of *new_ice -> " << new_ice << std::endl;	
	std::cout << "Addr of *cure -> " << cure << "\nAddr of *new_cure -> " << new_cure << std::endl;	

	delete ice;
	delete new_ice;
	delete cure;
	delete new_cure;
}