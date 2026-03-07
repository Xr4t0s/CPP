#ifndef __SWAP_TPP__
#define __SWAP_TPP__

template< typename T >
void	swap( T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

#endif
