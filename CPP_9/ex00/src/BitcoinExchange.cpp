#include "BitcoinExchange.hpp"

std::map<std::string, double>	rate;
std::ifstream									fs;

void	processLine(std::string line, uint nLine) {
	size_t sep = line.find('|');

	if (sep == std::string::npos) {
		buildErr(BAD_VALUE, line, nLine);
	}

	if (line.substr(sep + 1).find('|') != std::string::npos)
		buildErr(BAD_VALUE, line, nLine);
	
	std::string date = line.substr(0, sep);
	std::string value = line.substr(sep + 1);

	{
		while (!date.empty() && date[0] == ' ')
			date.erase(0, 1);
		while (!date.empty() && date[date.size() - 1] == ' ')
			date.erase(date.size() - 1);
		while (!value.empty() && value[0] == ' ')
			value.erase(0, 1);
		while (!value.empty() && value[value.size() - 1] == ' ')
			value.erase(value.size() - 1);
	}

	int mark = 0;

	for (size_t i = 0; i < value.size(); i++)
	{
			if (value[i] == '.')
			{
					mark++;
					if (mark > 1)
							buildErr(BAD_VALUE, line, nLine);
			}
			else if (!isdigit(value[i]))
					buildErr(BAD_VALUE, line, nLine);
	}

	if (value.empty() || date.empty())
			buildErr(BAD_VALUE, line, nLine);

	double converted_value = std::strtod(value.c_str(), NULL);
	if (converted_value < 0 || converted_value > 1000) {
		std::string intel;
		if (converted_value < 0)
			buildErr(BAD_VALUE, line, nLine, "Negative number");
		else
			buildErr(BAD_VALUE, line, nLine, "Too large number");
	}

	{
		std::size_t pos = date.find('-');
		if (pos == std::string::npos || pos != 4)
			buildErr(BAD_DATE, line, nLine, "Not a valid date");
		std::string tmp = date.substr(pos + 1);
		pos = tmp.find('-');
		std::string month = tmp.substr(0, 2);
		std::string day = tmp.substr(pos + 1, 2);

		int check;
		{
			check = std::atoi(month.c_str());
			if (check > 12 || check < 1)
				buildErr(BAD_DATE, line, nLine, "Not a valid month");
			for (int i = 0; month[i]; i++) {
				if (!isdigit(month[i]))
					buildErr(BAD_DATE, line, nLine, "Not a valid month");
			}

			check = std::atoi(day.c_str());
			if (check > 31 || check < 1)
				buildErr(BAD_DATE, line, nLine, "Not a valid day");
			for (int i = 0; day[i]; i++) {
				if (!isdigit(day[i]))
					buildErr(BAD_VALUE, line, nLine, "Not a valid day");
			}
		}

		if (day.length() != 2 || month.length() != 2)
			buildErr(BAD_DATE, line, nLine, "Not a valid date");

		pos = day.find('-');
		if (pos != std::string::npos)
			buildErr(BAD_DATE, line, nLine, "Not a valid date");
	}
	
	std::map<std::string, double>::iterator it = rate.lower_bound(date);
	if (it == rate.begin() && it->first != date)
		throw buildErr(BAD_DATE, line, nLine, "No earlier date");
	if (it != rate.begin() && it->first != date)
		--it;
	std::cout	<<
		date		<<
		" => "	<<
		value		<<
		" = "		<<
		it->second * converted_value <<
	std::endl;
}

void run() {	
	std::string tmp;
	uint		nLines = 1;

	std::getline(fs, tmp);

	if (tmp != "date | value")
		throw FileError(BAD_HEADER, "Need \"date | value\" at line 1");

	while (std::getline(fs, tmp)) {
		nLines++;
		try {
			processLine(tmp, nLines);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
}