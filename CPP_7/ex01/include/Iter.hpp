#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template< typename T, typename F >
void	iter( T *addr, const std::size_t len, F f);

#include "Iter.tpp"

#endif