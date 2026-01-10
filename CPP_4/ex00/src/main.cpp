#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "==============================\n";
	std::cout << " BASIC POLYMORPHISM TEST\n";
	std::cout << "==============================\n";

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\n==============================\n";
	std::cout << " COPY CONSTRUCTOR TEST\n";
	std::cout << "==============================\n";

	Dog dog1;
	Dog dog2(dog1); // constructeur de copie

	Cat cat1;
	Cat cat2(cat1);

	std::cout << "dog1 addr: " << &dog1 << std::endl;
	std::cout << "dog2 addr: " << &dog2 << std::endl;

	std::cout << "cat1 addr: " << &cat1 << std::endl;
	std::cout << "cat2 addr: " << &cat2 << std::endl;

	std::cout << "\n==============================\n";
	std::cout << " ASSIGNMENT OPERATOR TEST\n";
	std::cout << "==============================\n";

	Dog dog3;
	dog3 = dog1;

	Cat cat3;
	cat3 = cat1;

	std::cout << "dog3 addr: " << &dog3 << std::endl;
	std::cout << "cat3 addr: " << &cat3 << std::endl;

	std::cout << "\n==============================\n";
	std::cout << " POLYMORPHIC ARRAY TEST\n";
	std::cout << "==============================\n";

	const int size = 4;
	const Animal* animals[size];

	for (int k = 0; k < size; k++)
	{
		if (k % 2 == 0)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}

	for (int k = 0; k < size; k++)
	{
		std::cout << animals[k]->getType() << " -> ";
		animals[k]->makeSound();
	}

	for (int k = 0; k < size; k++)
		delete animals[k];

	std::cout << "\n==============================\n";
	std::cout << " OBJECT SLICING TEST\n";
	std::cout << "==============================\n";

	Dog realDog;
	Animal slicedAnimal = realDog; // slicing volontaire

	std::cout << "realDog type: " << realDog.getType() << std::endl;
	std::cout << "slicedAnimal type: " << slicedAnimal.getType() << std::endl;

	std::cout << "realDog sound: ";
	realDog.makeSound();

	std::cout << "slicedAnimal sound: ";
	slicedAnimal.makeSound();

	std::cout << "\n==============================\n";
	std::cout << " WRONG ANIMAL TEST\n";
	std::cout << "==============================\n";

	const WrongAnimal* wrong = new WrongCat();

	std::cout << wrong->getType() << std::endl;
	wrong->makeSound(); // DOIT appeler WrongAnimal

	delete wrong;

	std::cout << "\n==============================\n";
	std::cout << " STACK VS HEAP TEST\n";
	std::cout << "==============================\n";

	Animal stackAnimal;
	Animal* heapAnimal = new Animal();

	std::cout << "stackAnimal addr: " << &stackAnimal << std::endl;
	std::cout << "heapAnimal addr: " << heapAnimal << std::endl;

	delete heapAnimal;

	std::cout << "\n==============================\n";
	std::cout << " END OF TESTS\n";
	std::cout << "==============================\n";

	return 0;
}
