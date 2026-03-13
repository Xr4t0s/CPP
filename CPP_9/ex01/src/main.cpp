#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Usage" << std::endl;
		return 1;
	}

	try {
		run(av[1]);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}