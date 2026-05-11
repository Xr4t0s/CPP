#ifndef __OUTPUT_HPP__
#define __OUTPUT_HPP__

#include "utils/Types.hpp"

enum Type {
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	UNKNOWN
};

class Output {
	public:
		OutputChar		output_char;
		OutputInt		output_int;
		OutputDouble	output_double;
		OutputFloat		output_float;

		Output();
		Output(const Output& copy);
		Output& operator=(const Output& rhs);

		void display() const;
		void complete_from(const Type& from, bool display);

		~Output();
};

#endif