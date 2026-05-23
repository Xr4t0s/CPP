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
		bool					_addedZero;
	
		void					createOrderedPairs(char* input[]);
		RetContainer	jacobsthal();
		RetContainer	setOrderFromJacobsthal(RetContainer jacob);
		void					sort(RetContainer order);

	public:
		RetContainer	_ret;

		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe&	operator=(const PmergeMe& rhs);

		double run(char* input[]);

		~PmergeMe();
	
	public:
		typedef typename Container::iterator PairIterator;
		typedef typename RetContainer::iterator RetIterator;

		struct InvalidToken : std::exception {
			public:
				const char* what() const throw();
		};
};

#include "PmergeMe.tpp"

#endif