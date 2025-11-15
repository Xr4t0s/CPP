#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap ct = ClapTrap("Foo");

	ct.attack("Bar");
	ct.takeDamage(20);
	ct.beRepaired(10);
}