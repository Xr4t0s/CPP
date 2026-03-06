#ifndef __OUTPUT_TYPES_HPP__
#define __OUTPUT_TYPES_HPP__

#include <iostream>
#include <cmath>

class		OutputChar {
	public:
		char self;
		bool displayable;
		bool error;

		OutputChar();
		OutputChar(const OutputChar& copy);
		OutputChar& operator=(const OutputChar& rhs);

		void display() const;

		~OutputChar();
};

class		OutputInt {
	public:
		int self;
		bool displayable;
		bool error;

		OutputInt();
		OutputInt(const OutputInt& copy);
		OutputInt& operator=(const OutputInt& rhs);

		void display() const;
		
		~OutputInt();
};

class		OutputDouble {
	public:
		double self;
		bool displayable;
		bool error;

		OutputDouble();
		OutputDouble(const OutputDouble& copy);
		OutputDouble& operator=(const OutputDouble& rhs);

		void display() const;
		
		~OutputDouble();
};

class		OutputFloat {
	public:
		float self;
		bool displayable;
		bool error;

		OutputFloat();
		OutputFloat(const OutputFloat& copy);
		OutputFloat& operator=(const OutputFloat& rhs);

		void display() const;
		
		~OutputFloat();
};

#endif