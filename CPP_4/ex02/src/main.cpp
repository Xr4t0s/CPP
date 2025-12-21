#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	AAnimal* j = new Dog();
	AAnimal* i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;

	// AAnimal* x = new Animal(); // this is impossible bc AAnimal class is an abstraction
}