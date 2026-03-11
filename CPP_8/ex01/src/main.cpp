#include <iostream>
#include <vector>

#include "Span.hpp"

int main() {
	Span< std::vector<int> > span;

	try {
		span.addNumber(100);
		span.addNumber(-100);
		span.addNumber(-40);
		span.addNumber(-5);
		span.addNumber(0);
		span.addNumber(5);
		span.addNumber(40);
		std::cout << span << std::endl;
		std::cout << "Longest : " << span.longestSpan() << std::endl;
		std::cout << "Shortest : " << span.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}