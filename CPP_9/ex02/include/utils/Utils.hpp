#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>

typedef unsigned int uint;

template< typename T >
void	displayPairs(const T& pairs);

template< typename T >
void	displayContainer(const T& container);

std::vector< std::pair<uint, uint> > generateRandomVector(size_t n);
// std::deque< std::pair<uint, uint> > generateRandomDeque(size_t n);

bool	comparePair(const std::pair<uint, uint>& a, const std::pair<uint, uint>& b);

#include "utils/Utils.tpp"

#endif