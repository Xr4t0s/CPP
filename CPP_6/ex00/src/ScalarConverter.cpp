#include "ScalarConverter.hpp"
#include "utils/Output.hpp"

static Type parser(const std::string& str) {
	int i = 0;
	int p = 0;

	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	else if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
		return DOUBLE;
	else if (str == "-inff" || str == "+inff" || str == "inff" || str == "nanf")
		return FLOAT;
	else
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		while(isdigit(str[i]))
			i++;
		if (!str[i])
			return INT;
		if (str[i] == '.')
		{
			p++;
			i++;
			while(isdigit(str[i]))
				i++;
		}
		if (!str[i] && isdigit(str[i - 1]))
			return DOUBLE;
		if (str[i] && (i + 1) == static_cast<int>(str.length()) && str[i] == 'f' && isdigit(str[i - 1]) && p)
			return FLOAT;
		else
			return UNKNOWN;
	}
}

const char* ScalarConverter::ConvertError::what() const throw() {
	return "Conversion error";
}

void	ScalarConverter::convert( const std::string& arg ) {

	Output ret;

	Type typeof_arg = parser(arg);

	switch (typeof_arg) {
		case CHAR:
			ret.output_char.self = arg[0];
			ret.complete_from(CHAR, true);
			break;

		case INT:
			ret.output_int.self = std::atoi(arg.c_str());
			ret.complete_from(INT, true);
			break;

		case DOUBLE:
			ret.output_double.self = std::strtod(arg.c_str(), NULL);
			ret.complete_from(DOUBLE, true);
			break;
		
		case FLOAT:
			ret.output_float.self = std::strtof(arg.c_str(), NULL);
			ret.complete_from(FLOAT, true);
			break;

		default:
			throw ConvertError();
			break;
	}
}