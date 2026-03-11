#include "easyfind.hpp"

int main() {
	std::vector<int> vec;

	vec.push_back(0);
	vec.push_back(1);

	std::vector<int>::iterator ret;

	try {
		ret = easyfind(vec, 1);
		std::cout << ret.base() << std::endl;
		ret++;
		std::cout << ret.base() << std::endl;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}