#include "Data.hpp"

Data::Data() : a(1), b(2), name("test") {}
Data::Data(int a_value, int b_value) : a(a_value), b(b_value), name("test") {}
Data::Data(const Data& copy) : a(copy.a), b(copy.b), name("test") {}
Data&	Data::operator=(const Data& rhs) {
	if (this != &rhs) {
		this->a = rhs.a;
		this->b = rhs.b;
		this->name = rhs.name;
	}
	return *this;
}
Data::~Data() {}