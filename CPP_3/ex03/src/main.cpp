#include "DiamondTrap.hpp"

int main( void ) {
	ClapTrap ct = ClapTrap("FooClap");
	DiamondTrap st = DiamondTrap("FooDiamond");

	ct.attack("BarClap");
	st.attack("BarDiamond");
	st.whoAmI();
}