#ifndef __MIN_TPP__
#define __MIN_TPP__

template< typename T >
T	min(const T& a, const T& b) {
	return a >= b ? b : a;
}

#endif
