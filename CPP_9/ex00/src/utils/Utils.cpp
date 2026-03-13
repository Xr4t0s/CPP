#include "utils/Utils.hpp"
#include "BitcoinExchange.hpp"

void verifyFile(int ac, char **av) {
	if (ac != 2)
		throw UsageError();

	fs.open(av[1], std::fstream::in);

	if (!fs.is_open()) {
		std::string intel = "Can't open \"";
		intel.append(av[1]);
		intel.append("\"");
		throw FileError(BAD_FILE, intel);
	}
}

void	loadDatabase() {
	const char* filename = "./attachments/data.csv";

	std::ifstream db_fs(filename);

	if (!db_fs) {
		std::string intel = "Can't open \"";
		intel.append(filename);
		intel.append("\"");
		throw FileError(BAD_FILE, intel);
	}

	std::string tmp;
	std::getline(db_fs, tmp);

	if (tmp != "date,exchange_rate")
		throw FileError(BAD_HEADER, "Bad header in database, need \"date,exchange_rate\" at line 1");
	
	while (std::getline(db_fs, tmp)) {
		size_t sep = tmp.find(',');

		if (sep == std::string::npos)
			throw FileError(BAD_VALUE, "Bad value in database, you mustn't touch this file");
		
		std::string date = tmp.substr(0, sep);
		std::string value = tmp.substr(sep + 1);
		rate[date] = std::strtod(value.c_str(), NULL);
	}
}
