#include "easyfind.hpp"

template< typename T>
typename T::iterator easyfind(T& unknown,double val) {
	typename T::iterator ret = std::find(unknown.begin(), unknown.end(), val);

	if (!*ret) throw NoOcurrenceFound();
	
	return ret;
}