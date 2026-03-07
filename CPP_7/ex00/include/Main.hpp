#ifndef __MAIN_TPP__
#define __MAIN_TPP__

template< typename T >
T	max(const T& a, const T& b);

template< typename T >
T	min(const T& a, const T& b);

template< typename T >
void	swap( T& a, T& b);

#include "Max.tpp"
#include "Min.tpp"
#include "Swap.tpp"

#endif
