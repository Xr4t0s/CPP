#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	
	return 0;
}