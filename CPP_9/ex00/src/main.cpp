#include "BitcoinExchange.hpp"
#include "utils/Parser.hpp"

int main(int ac, char **av) {
	try {
		verifyFile(ac, av);		
	} catch (std::exception& e) {
		std::cout << e.what();
	}
}