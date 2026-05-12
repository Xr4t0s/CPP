#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

#include <iostream>

template< typename T>
class Array {
	private:
		T*				_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& rhs);
		
		T&	operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		unsigned int size() const;

		~Array();
	
	public:
		struct OutOfRangeIndex : std::exception {
			public:
				const char* what() const throw();
		};
};

#include "Array.tpp"

#endif
