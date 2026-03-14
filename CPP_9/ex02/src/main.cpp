#include "PmergeMe.hpp"

typedef PmergeMe<std::vector< std::pair<uint,uint> >,	std::vector<int> > PmergeMeWithVector;
typedef PmergeMe<std::deque< std::pair<uint,uint> >,	std::deque<int> > PmergeMeWithDeque;
typedef PmergeMe<std::list< std::pair<uint,uint> >,	std::list<int> > PmergeMeWithList;

int main(int ac, char* av[]) {
	if (ac < 3) return 1;

	int i = 0;
	std::cout << "Begin : ";
	for (i = 1; av[i]; i++) {
		std::cout << av[i] << (av[i + 1] ? ", " : ".\n");
	}

	try {
		PmergeMeWithVector a;
		double elapsed_ms = a.run(++av);
		std::cout << "After : ";
		displayContainer(a._ret);
		std::cout << "Time to process a range of " << i - 1 << " elements with std::vector : " << elapsed_ms << " us" << std::endl;

		PmergeMeWithDeque b;
		elapsed_ms = b.run(av);
		std::cout << "Time to process a range of " << i - 1 << " elements with std::deque : " << elapsed_ms << " us" << std::endl;

	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}