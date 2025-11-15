#include "Zombie.hpp"

int main() {
	Zombie* heap = newZombie("heap");
	
	heap->announce();

	randomChump("stack");

	delete heap;
}