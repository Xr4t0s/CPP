#include "Array.hpp"

template< typename T>
Array<T>::Array() {
	this->_array = new T[0]();
	this->_size = 0;
}

template< typename T>
Array<T>::Array(unsigned int n) {
	this->_array = new T[n]();
	this->_size = n;
}

template< typename T>
Array<T>::Array(const Array& copy) {
	this->_array = new T[copy._size]();

	for (unsigned int i = 0; i < copy._size; i++) {
		this->_array[i] = copy._array[i];
	}
	this->_size = copy._size;
}

template< typename T>
Array<T>&	Array<T>::operator=(const Array& rhs) {
	if (this != &rhs) {
		delete[] this->_array;
		this->_array = new T[rhs._size]();
		for (unsigned int i = 0; i < rhs._size; i++) {
			this->_array[i] = rhs._array[i];
		}
		this->_size = rhs._size;
	}
	return *this;
}

template< typename T>
const char* Array<T>::OutOfRangeIndex::what() const throw() {
	return "Index out of range";
}

template< typename T>
T& Array<T>::operator[](unsigned int index) {
	if (this->_size <= index)
		throw Array::OutOfRangeIndex();
	return this->_array[index];
}

template< typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (this->_size <= index)
		throw Array::OutOfRangeIndex();
	return this->_array[index];
}

template< typename T >
unsigned int Array<T>::size() const {
	return this->_size;
}

template< typename T>
Array<T>::~Array() {
	delete[] this->_array;
}
