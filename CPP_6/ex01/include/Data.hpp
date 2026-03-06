#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <iostream>

class Data {
	public:
		Data();
		Data(int a_value, int b_value);
		Data( const Data& copy );
		Data& operator=(const Data& rhs);
		
		int a;
		int b;
		std::string name;

		~Data();
};

#endif