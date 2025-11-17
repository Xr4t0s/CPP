#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Animal* animal = new Animal();
	animal->makeSound();
	std::cout << "Animal type :\t" << animal->getType() << std::endl;
	delete animal;
	std::cout << std::endl;
	
	Cat* cat = new Cat();
	cat->makeSound();
	std::cout << "Cat type :\t" << cat->getType() << std::endl;
	delete cat;
	std::cout << std::endl;
	
	
	Dog* dog = new Dog();
	dog->makeSound();
	std::cout << "Dog type :\t" << dog->getType() << std::endl;
	delete dog;
}