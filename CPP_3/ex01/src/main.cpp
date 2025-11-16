#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap ct = ClapTrap("FooClap");
	ScavTrap st = ScavTrap("FooScav");

	ct.attack("BarClap");
	st.attack("BarScav");
	ct.beRepaired(10);
	st.beRepaired(10);
	ct.takeDamage(10);
	st.takeDamage(10);
	st.guardGate();
}