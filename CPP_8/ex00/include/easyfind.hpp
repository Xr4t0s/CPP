#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <iostream>
#include <algorithm>
#include <vector>

struct NoOcurrenceFound : std::exception {
	public:
		const char* what() const throw();
};

template< typename T>
typename T::iterator easyfind(T&, int);

#include "easyfind.tpp"

#endif