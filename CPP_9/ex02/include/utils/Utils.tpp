#include "utils/Utils.hpp"

template< typename T>
void	displayPairs(const T& pairs) {
	for (std::size_t i = 0; i < pairs.size(); i++) {
		std::cout << "(" << pairs[i].first << "," << pairs[i].second << ")" << std::endl;
	}
	std::cout << "\n";
}

template< typename T>
void	displayContainer(const T& container) {
	for (std::size_t i = 0; i < container.size(); i++) {
		if (i != 0)
			std::cout << ", ";
		std::cout << container[i];
	}
	std::cout << ".\n";
}