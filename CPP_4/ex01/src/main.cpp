#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const int size = 10;
	Animal* zoo[size];

	for (int i = 0; i < size; i++)
	{
		if (i % 2)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}

	for (int i = 0; i < size; i++)
		delete zoo[i];

	return 0;
}
