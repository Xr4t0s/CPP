#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>
#include <stack>
#include <deque>

template< typename T >
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack& copy);
		MutantStack& operator=(const MutantStack& rhs);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin();
		iterator	end();

		~MutantStack();
};

#include "MutantStack.tpp"

#endif