#include <iostream>
#include <vector>

#include "Span.hpp"

int main() {
	Span< std::vector<int> > span(100000000);

	try {
		std::vector<int> tab;
		
		for (int i = 0; i < 99999999; i++) {
			tab.push_back(i);
		}

		span.addNumber(tab.begin(), tab.end());
		
		std::cout << span << std::endl;
		std::cout << "Longest : " << span.longestSpan() << std::endl;
		std::cout << "Shortest : " << span.shortestSpan() << std::endl;
		
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}