#include "utils/Utils.hpp"

std::vector<std::pair<uint, uint> > generateRandomVector(size_t n) {
	std::vector<std::pair<uint, uint> > pairs;
	std::srand(std::time(NULL));

	for (size_t i = 0; i < n; i++) {
		uint a = std::rand() % 1000;
		uint b = std::rand() % 1000;

		if (a < b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	return pairs;
}

bool	comparePair(const std::pair<uint, uint>& a, const std::pair<uint, uint>& b) {
	return a.second < b.second;
}
