#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* j = new Dog();
	Animal* i = new Cat();
	std::cout << std::endl;
	delete j;//should not create a leak
	delete i;
	std::cout << std::endl;
	std::cout << std::endl;
	
	j = new Dog();
	i = new Cat();
	Animal* meta = new Animal();
	std::cout << std::endl;
	
	j->makeSound();
	i->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	
	delete j;
	delete i;
	delete meta;
	std::cout << std::endl;
	std::cout << std::endl;

	Animal* arr[100];

	for (int index = 0; index < 100; index++) {
		index > 50 ? arr[index] = new Dog() : arr[index] = new Cat();
	}
	for (int index = 0; index < 100; index++) {
		arr[index]->makeSound();
	}
	for (int index = 0; index < 100; index++) {
		delete arr[index];
	}
}