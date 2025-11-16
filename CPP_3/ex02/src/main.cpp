#include "FragTrap.hpp"

int main( void ) {
	ClapTrap ct = ClapTrap("FooClap");
	FragTrap st = FragTrap("FooFrag");

	ct.attack("BarClap");
	st.attack("BarFrag");
	ct.beRepaired(10);
	st.beRepaired(10);
	ct.takeDamage(10);
	st.takeDamage(10);
	st.highFivesGuys();
}