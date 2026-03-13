#include "utils/Parser.hpp"


void verifyFile(int ac, char **av) {
	if (ac != 2)
		throw UsageError();
	
	std::ifstream fs;

	fs.open(av[1], std::fstream::in);

	if (!fs.is_open())
		throw FileError();

	std::string tmp;
	uint		nLines = 0;
	while (std::getline(fs, tmp)) {
		nLines++;
		if (*(std::find(tmp.begin(), tmp.end(), '|')) == 0)
			throw FileError();
		std::cout << tmp << std::endl;
	}
}
