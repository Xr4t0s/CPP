#include "BitcoinExchange.hpp"
#include "utils/Utils.hpp"

int main(int ac, char **av) {
	try {
		verifyFile(ac, av);
		loadDatabase();
		run();
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}