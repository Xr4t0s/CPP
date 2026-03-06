#ifndef __SCALAR_CONVERTER_HPP__
#define __SCALAR_CONVERTER_HPP__

#include <iostream>
#include <cmath>
#include <cstdlib>

class ScalarConverter {

	public:
		struct ConvertError : std::exception {
			virtual const char* what() const throw();
		};

		static void	convert( const std::string& arg );

		virtual ~ScalarConverter() = 0;

};

#endif