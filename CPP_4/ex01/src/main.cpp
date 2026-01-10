#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "==============================\n";
	std::cout << " REAL DEEP COPY PROOF TEST\n";
	std::cout << "==============================\n";

	Dog a;
	a.getBrain()->setIdea(0, "I am dog A");
	a.getBrain()->setIdea(1, "Second idea A");

	Dog b(a); // copy constructor
	Dog c;
	c = a;    // assignment operator

	std::cout << "\n--- Initial state ---\n";
	std::cout << "a idea[0]: " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "b idea[0]: " << b.getBrain()->getIdea(0) << std::endl;
	std::cout << "c idea[0]: " << c.getBrain()->getIdea(0) << std::endl;

	a.getBrain()->setIdea(0, "I changed A");

	std::cout << "\n--- After modifying A ---\n";
	std::cout << "a idea[0]: " << a.getBrain()->getIdea(0) << std::endl;
	std::cout << "b idea[0]: " << b.getBrain()->getIdea(0) << std::endl;
	std::cout << "c idea[0]: " << c.getBrain()->getIdea(0) << std::endl;

	std::cout << "\nEXPECTED:\n";
	std::cout << "- a : I changed A\n";
	std::cout << "- b : I am dog A\n";
	std::cout << "- c : I am dog A\n";

	/* ============================== */

	std::cout << "\n==============================\n";
	std::cout << " POLYMORPHIC DELETE STRESS TEST\n";
	std::cout << "==============================\n";

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

	std::cout << "\n==============================\n";
	std::cout << " END — IF NO LEAK / NO CRASH = PERFECT\n";
	std::cout << "==============================\n";

	return 0;
}
