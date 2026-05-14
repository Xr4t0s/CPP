#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <algorithm>

typedef unsigned int uint;

template< typename Container >
class Span {
	private:
		Container	_array;
		uint			_size;
	
	public:
		Span(uint);
		Span(const Span&);
		Span& operator=(const Span&);

		Container getArray() const;

		void	addNumber(uint);

		template <typename Iterator>
		void	addNumber(Iterator begin, Iterator end);

		int	shortestSpan() const;
		int	longestSpan() const;

		~Span();

	public:
		struct NoSpaceLeft : std::exception {
			public:
				const char* what() const throw();
		};
		struct InvalidSize : std::exception {
			public:
				const char* what() const throw();
		};
};

template< typename Container >
std::ostream& operator<<(std::ostream& os, Span<Container>& span);

#include "Span.tpp"

#endif