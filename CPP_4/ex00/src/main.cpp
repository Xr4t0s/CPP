#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	
	delete meta;
	delete j;
	delete i;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	wrong->makeSound();
	wrongCat->makeSound();

	delete wrongCat;
	delete wrong;

	return 0;
}