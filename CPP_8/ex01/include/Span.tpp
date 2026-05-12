#include "Span.hpp"

template< typename Container >
Span<Container>::Span() : _array(0), _size(0) {}

template< typename Container >
Span<Container>::Span(uint size) : _array(0), _size(size) {}

template< typename Container >
Span<Container>::Span(const Span<Container>& copy) : _array(copy._array), _size(copy._size) {}

template< typename Container >
Span<Container>& Span<Container>::operator=(const Span<Container>& rhs) {
	if (this != &rhs) {
		this._array = rhs._array;
		this->_size = rhs._size;
	}
	return *this;
}

template< typename Container >
Span<Container>::~Span() {}



template< typename Container >
Container	Span<Container>::getArray() const {
	return _array;
}

template< typename Container >
void	Span<Container>::addNumber(uint num) {
	if (_array.size() + 1 > _size)
		throw NoSpaceLeft();
	_array.push_back(num);
}

template< typename Container >
int	Span<Container>::shortestSpan() const {
	if (_array.size() < 2)
		throw InvalidSize();

	Container copy = getArray();
	
	typename Container::iterator it = copy.begin();
	typename Container::iterator ite = copy.end();

	std::sort(it, ite);

	int ret = __INT_MAX__;
	while (it != ite) {
		int left = *it;
		typename Container::iterator tmp = it;
		tmp++;
		int right = *tmp;
		if (right - left < ret)
			ret = right - left;
		++it;
		typename Container::iterator breakpoint = it;
		if (++breakpoint == ite)
			break;
	}
	
	return ret;
}

template< typename Container >
int	Span<Container>::longestSpan() const {
	if (_array.size() < 2)
		throw InvalidSize();
	typename Container::const_iterator min = std::min_element(_array.begin(), _array.end());
	typename Container::const_iterator max = std::max_element(_array.begin(), _array.end());

	int ret = *max - *min;

	return ret;
}


template< typename Container >
const char* Span<Container>::NoSpaceLeft::what() const throw() {
	return "No space left in this container";
}
template< typename Container >
const char* Span<Container>::InvalidSize::what() const throw() {
	return "The size of the container is not valid for span search";
}


template< typename Container >
std::ostream& operator<<(std::ostream& os, Span<Container>& span)
{
	Container copy = span.getArray();
	typename Container::iterator it = copy.begin();

	while (it != copy.end())
	{
		os << *it;
		typename Container::iterator next = it;
		++next;
		if (next != copy.end())
				os << ", ";
		else
				os << ".";
		++it;
	}

	return os;
}