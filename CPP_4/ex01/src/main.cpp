#include "Dog.hpp"

int main() {
	// Animal* arr[100];

	// for (int i = 0; i < 5; i++) {
	// 	if (i < 2)
	// 		arr[i] = new Dog();
	// 	else
	// 		arr[i] = new Dog();
	// }

	// for (int i = 0; i < 5; i++) {
	// 	arr[i]->makeSound();
	// }

	// for (int i = 0; i < 5; i++) {
	// 	delete arr[i];
	// }

	// Test deep copy
	Dog a;
	Dog b(a);

	Dog c;
	c = a;

	return 0;
}
