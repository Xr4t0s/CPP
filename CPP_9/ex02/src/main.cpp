#include "PmergeMe.hpp"

typedef PmergeMe<std::vector< std::pair<uint,uint> >,	std::vector<int> > PmergeMeWithVector;
typedef PmergeMe<std::deque< std::pair<uint,uint> >,	std::deque<int> > PmergeMeWithDeque;

int main(int ac, char* av[]) {
	if (ac < 3) return 1;

	try {
		PmergeMeWithVector a;
		a.run(++av, true);
		PmergeMeWithDeque b;
		b.run(av, true);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}