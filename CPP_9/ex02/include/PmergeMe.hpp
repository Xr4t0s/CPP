#ifndef __PMERGE_ME_HPP__
#define __PMERGE_ME_HPP__

#include <algorithm>
#include <sstream>
#include <utility>

#include "utils/Utils.hpp"

template<typename Container, typename RetContainer>
class PmergeMe {
	private:
		Container			_pairs;
		RetContainer	_ret;
		bool					_addedZero;
	
		void					createOrderedPairs(char* input[]);
		RetContainer	jacobsthal();
		RetContainer	setOrderFromJacobsthal(RetContainer jacob);
		void					sort(RetContainer order);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe&	operator=(const PmergeMe& rhs);

		void run(char* input[], bool verbose);

		~PmergeMe();
	
	public:
		typedef typename Container::iterator PairIterator;
		typedef typename RetContainer::iterator RetIterator;
};

#include "PmergeMe.tpp"

#endif