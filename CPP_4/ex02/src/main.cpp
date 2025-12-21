#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const AAnimal* a = new Dog();
	a->makeSound();
	std::cout << "Type of Dog -> " << a->getType() << std::endl;

	std::cout << std::endl;
	
    const AAnimal* b = new Cat();
	b->makeSound();
	std::cout << "Type of Cat -> " << b->getType() << std::endl;
	
	std::cout << std::endl;

	delete b;
}


// int main() {
// 	const Animal* a = new Dog();
// 	const Animal* b = new Cat();

// 	delete a;
// 	delete b;
// }